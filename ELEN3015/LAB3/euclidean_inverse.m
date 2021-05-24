function h = euclidean_inverse(e,n)


%This uses the Extended Euclidean Algorithm to find the decryption key h
    q1 = 1;
    divisor = e;
    newdividend = 0;
    dividend = n;
    flag = 1;

% Computes a = bq + r in reverse
    while dividend ~= 0
        temp = floor(divisor/dividend);
        modd = mod(divisor,dividend);
        newa = q1 + temp * newdividend;
        q1 = newdividend;
        newdividend = newa;
        divisor = dividend;
        dividend = modd;
        flag = flag *(-1);
    end
    
    if (flag < 0)
        h = n - q1;
    else
        h = q1;
    end

end