

p = primeGenerator()
q = primeGenerator()

m = p*q
euler_Totient_m = (p-1)*(q-1);

%Determine public-key s
s = randi([2 euler_Totient_m ]);        %size of s between 2 and euler_totient(m)
while (gcd(s,euler_Totient_m) ~= 1)
    s = randi([2 euler_Totient_m]);
end
s
%Determine the private-key h
h = euclidean_inverse(s,euler_Totient_m)

%Generate 1000 random numbers,with each number between 1000 and 9999,and
%encrypts each one using the public key (s,m)
message = [];
ciphertext = [];
plaintext = [];

for l=1:1000
    message(l) = randi([1000 9999]);
    while (message(l) > m)
        message(l) = randi([1000 9999]);    %Ensures the message is smaller than m
    end
end

start_time1 = cputime;

for i=1:1000
ciphertext(i) = bigMod(message(i),s,m);         % c = m.^e mod(n)
end

encryption_time = cputime - start_time1

%Decryption
start_time2 = cputime;

for j=1:1000
plaintext(j) = bigMod(ciphertext(j),h,m);       % m = c.^d mod(n)
end

decryption_time = cputime - start_time2

%Check to see if ciphertext decrypted correctly
if (isequal(message,plaintext) == 1)
    disp('Ciphertext decrypts correctly - algorithm is correct')
else
    disp('Algorithm not correct')
end



