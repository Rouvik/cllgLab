import re
from enum import Enum

class Tokens(Enum):
    atom = 1
    op = 2
    exp = 3
    eof = 4

class Lexer:
    def __init__(self, text) -> None:
        self.text = text
        self.cur = 0

    def next(self) -> tuple[str, Tokens]:
        token = ""

        while self.cur < len(self.text):
            ch = self.text[self.cur]
            self.cur += 1

            if re.match("[+|\\-|*|\\/|\\(|\\)]", ch):
                if len(token) == 0:
                    return (ch, Tokens.op)
                else:
                    self.cur -= 1               # Unread the operator
                    return (token, Tokens.atom)
                
            if re.match("[ \\n\\t]", ch):
                if len(token) != 0:
                    return (token, Tokens.atom)
                else:
                    continue
            
            token += ch

        if len(token) != 0:
            return (token, Tokens.atom)

        return ('', Tokens.eof)

    def peek(self) -> tuple[str, Tokens]:
        curPos = self.cur
        tok = self.next()
        self.cur = curPos
        return tok
    
    def reset(self, newText = None):
        if newText is not None:
            self.text = newText
        
        self.cur = 0

class Expression:
    class ExprType(Enum):
        Single = 1
        Operation = 2

    def __init__(self, left, op, right, type = ExprType.Single):
        self.left : Expression = left
        self.op = op
        self.right : Expression = right
        self.type : Expression.ExprType = type

class PrattParser:
    binding_power_map = {
        "+": (1.0, 1.1),
        "-": (1.0, 1.1),
        "*": (2.0, 2.1),
        "/": (2.0, 2.1)
    }

    prefix_binding_power_map = {
        '+': (None, 5),
        '-': (None, 5)
    }

    def parseExpression(self, tokenizer : Lexer, min_bp):
        ntok = tokenizer.next()
        lhs = None

        # deal with parenthesis
        if ntok[1] == Tokens.op and ntok[0] == "(":
            lhs = self.parseExpression(tokenizer, 0)
            assert tokenizer.next()[0] == ")"
        else:
            match ntok[1]:
                case Tokens.atom: lhs = Expression(None, ntok[0], None, Expression.ExprType.Single)
                case Tokens.op:
                    _, rbp = *PrattParser.prefix_binding_power_map[ntok[0]],
                    rhs = self.parseExpression(tokenizer, rbp)
                    lhs = Expression(Expression(None, 0, None), ntok[0], rhs, Expression.ExprType.Operation)
                case _: raise Exception("Error bad expresssion")
        
        while True:
            ntok = tokenizer.peek()
            op = None

            # deal with parenthesis
            if ntok[1] == Tokens.op and ntok[0] == ")":
                break
            else:
                match ntok[1]:
                    case Tokens.eof: break
                    case Tokens.op: op = ntok[0]
                    case _: raise Exception(f"Bad token {ntok[0]}")
            
            lbp, rbp = *PrattParser.binding_power_map[op],

            if lbp < min_bp:
                break

            tokenizer.next()

            rhs = self.parseExpression(tokenizer, rbp)
            lhs = Expression(lhs, op, rhs, Expression.ExprType.Operation)

        return lhs
    
    def printExpression(self, expression : Expression):
        if expression is None:
            return

        print(f"({expression.op}", end='')
        self.printExpression(expression.left)
        self.printExpression(expression.right)
        print(")", end='')

    def solveExpresssion(self, expression : Expression):
        if expression is None:
            return None
        
        expression.left = self.solveExpresssion(expression.left)
        expression.right = self.solveExpresssion(expression.right)

        if expression.type == Expression.ExprType.Operation:
            val = 0
            match expression.op:
                case '+': val = float(expression.left.op) + float(expression.right.op)
                case '-': val = float(expression.left.op) - float(expression.right.op)
                case '*': val = float(expression.left.op) * float(expression.right.op)
                case '/': val = float(expression.left.op) / float(expression.right.op)

            return Expression(None, val, None, Expression.ExprType.Single)
        else:
            return expression
