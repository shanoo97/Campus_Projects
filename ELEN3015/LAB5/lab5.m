%1.1
in = [1 0 1 0];
%C1 generation using Hamming(7,4)
H1 = hammings(in);
C1=hammings(in);

%1.2
%C2 generation using equation g(x) = 1 + x + x^3
gx = [1 1 0 1];
C2=gfconv(in,gx);
C2(7) =0;
disp(C2);

%1.4
%Multiply codeword with binary digits corresponding to x^3 
C3 = add(in)

%1.5
%generating all possible 4 bit numbers
for j = 1:15
array(j,1:4) = dec2bin(j,4) - '0';
end

%multiply all the combinations with the generator matrix
for q = 1:15
C4(q,1:7) = hammings(array(q,1:4));
end

%Hammings distance calculation which should be the minimum distances
for i = 2:15
Xored(i-1,:) = xor(C4(i-1,:),C4(i,:));
array2(i-1) = sum(Xored(i-1,:)); %sum of everything is 1
end

%1.6
for index = 1:15
array3(index) = sum(C4(index,:));
end
minwei = min(array3);

%1.8
%Student number = 1240547
stunum = [5 4 7];
studentnumber =[5 4 7]
for a = 1:3
input(a,1:4)=dec2bin(stunum(a),4) - '0';
end
disp('Binary Rep of Student Num:');
disp(input);
for b = 1:3
  
C5(b,:) = hammings(input(b,:));
end
C5

%2.1
% tested c =  1010001
in0 = 0;
for o = 1:7
in0(o,1:4) = dec2bin(o,4) - '0';
end
for p = 1:7
C6(p,:) = hammings(in0(p,:));
end
disp('Message:')
disp(C6);
err_array = dlmread('input.txt')

for z = 1:7
rectified(z,:)= error_def(err_array(z,:));
end
disp('Rectified')
disp(rectified);
dlmwrite('output.txt',rectified,'\t')

%2.2
% tested c = 1010001
error_array = 0;
in0 = 0;
for o = 1:7
in0(o,1:4) = dec2bin(o,4) - '0';
end
for p = 1:7
    C6(p,:) = hammings(in0(p,:));
end
disp('Message:')
disp(C6);
error_array = dlmread('input.txt')

for z = 1:7
rectified(z,:)=errorCorrect(error_array(z,:));
end
disp('Rectified');
disp(rectified);
dlmwrite('output2.txt',rectified,'\t');