base3_to_dec()
{
    n=$1
    result=0
    power=1

    while [ $n -gt  0 ]; do
        digit=$(( n % 10 ))
        result=$(( result + digit * power ))
        power=$(( power * 3 ))
        n=$(( n / 10 ))
    done

    echo $result
}

dec_to_base5()
{
    n=$1
    if [ $n -eq 0 ]; then
        echo "0"
    fi

    res=""

    while (( n > 0 )); do
        res="$(( n % 5 ))$res"
        n=$(( n / 5 ))
    done

    echo $res
}

read -p "Enter a number: " n

dec_to_base5 $(base3_to_dec $n)