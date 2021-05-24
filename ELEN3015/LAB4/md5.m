

%used an online source for assistance for the coding 

function output = md5(text)

m = 2 ^ 32;
s = [-7, -12, -17, -22
-5,  -9, -14, -20
 -4, -11, -16, -23
 -6, -10, -15, -21];
t = floor(abs(sin(1:64)) .* m);
output = [hex2dec('67452301') ... %create row vector of 32 bit integers
hex2dec('EFCDAB89') ...
hex2dec('98BADCFE') ...
hex2dec('10325476')];
          
%if the text has characters convert to ASCII 
text = double(text);
bytelength = numel(text);
%padding bits
text = [text, 128, zeros(1, mod(55 - bytelength, 64))];

    % Convert the text to 32-bit integers, little endian
text = reshape(text, 4, numel(text) / 4);
text = text(1,:) + ...            % least significant byte
text(2,:) * 256 + ...
text(3,:) * 65536 + ...
text(4,:) * 16777216;      % most significant byte

    len = bytelength * 8;
    text = [text, mod(len, m), mod(len / m, m)];

    % Process each 512-bit block. Split 16 block of each 32 bits
 for k = 1:16:numel(text)
 a = output(1); b = output(2); c = output(3); d = output(4);
 for i = (1:64)
 bv = dec2bin(b, 32) - '0';
cv = dec2bin(c, 32) - '0';
dv = dec2bin(d, 32) - '0';
if i <= 16          % Round 1
 f = (bv & cv) | (~bv & dv);
 g = i - 1;
 r = 1;
 elseif i <= 32      % Round 2
 f = (bv & dv) | (cv & ~dv);
 g = mod(5 * i - 4, 16);
r = 2;
elseif i <= 48      % Round 3
f = xor(bv, xor(cv, dv));
g = mod(3 * i + 2, 16);
r = 3;
else                % Round 4
 f = xor(cv, bv | ~dv);
g = mod(7 * i - 7, 16);
 r = 4;
end
f = bin2dec(char(f + '0'));
 % perform circular shift 
sc = mod(i - 1, 4) + 1;
sum = mod(a + f + text(k + g) + t(i), m);
sum = dec2bin(sum, 32);
sum = circshift(sum, [0, s(r, sc)]);
sum = bin2dec(sum);
% Update a, b, c, d.
temp = d;
 d = c;
 c = b;
 b = mod(b + sum, m);
a = temp;
end 
 % Add hash to end of last block
output = mod(output + [a, b, c, d], m);
end 

 output = [output                % least significant byte
 output / 256
 output / 65536
output / 16777216];   % most significant byte
output = reshape(mod(floor(output), 256), 1, numel(output));
 % convert to hex
 output = dec2hex(output);
  output = reshape(transpose(output), 1, numel(output));   
end
    



