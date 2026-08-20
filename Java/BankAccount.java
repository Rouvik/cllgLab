import java.util.Scanner;

public class BankAccount {
	static double OVERDRAW = 5000.0;

	String name; int accNo; char type; double balance;

	BankAccount()
	{
		name = "Unknown";
		accNo = 0;
		type = 's';
		balance = 0.0;
	}

	BankAccount(String name, int accNo, char type, double balance)
	{
		this.name = name;
		this.accNo = accNo;
		this.type = type;
		this.balance = balance;
	}

	void checkBalance()
	{
		System.out.println("Current balance is: Rs. " + balance);
	}

	void withdraw(double amt)
	{
		if((balance >= amt) || (type == 'c' && amt <= OVERDRAW + balance))
		{
			balance -= amt;
			return;
		}

		System.out.println("Error, insufficient balance");
	}

	void deposit(double amt)
	{
		balance += amt;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		boolean running = true;

		String n; int an; char t; double b;

		System.out.print("Enter name: ");
		n = sc.nextLine();

		System.out.print("Enter account no: ");
		an = sc.nextInt();

		System.out.print("Enter account type (savings / current): ");
		t = sc.next().equals("savings") ? 's' : 'c';

		System.out.print("Enter initial balance: ");
		b = sc.nextDouble();

		BankAccount acc = new BankAccount(n, an, t, b);

		double x;

		while(running)
		{
			System.out.println("Enter choice:\n1) Deposit\n2) Withdraw\n3) Account info\n4) Check balance\n5) Exit\n> ");
			int ch = sc.nextInt();

			switch(ch)
			{
				case 1:
					System.out.print("Enter amount: ");
					x = sc.nextDouble();
					acc.deposit(x);
				break;

				case 2:
					System.out.print("Enter amount: ");
					x = sc.nextDouble();
					acc.withdraw(x);
				break;

				case 3:
					System.out.println(
						"Name: " + acc.name +
						"\nAcc no: " + acc.accNo +
						"\nAcc type: " + (acc.type == 's' ? "Savings" : "Current")
					);
					acc.checkBalance();
				break;

				case 4:
					acc.checkBalance();
				break;

				case 5: running = false; break;

				default: System.out.println("Error unknown choice");
			}
		}
	}
}
