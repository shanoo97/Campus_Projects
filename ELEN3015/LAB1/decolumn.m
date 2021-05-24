function x = decolumn(y,columns)
%
%  function x = decolumn(y,columns)
%
%  Decolumn - columnar transposition cipher, decipher function
%  Takes text in y and de-colmnizes it (assuming columns columns) into x.
%
%    By   G.D.Agnew  (c) 24/2/2001
%    

if (nargin<2)
   columns = 7;		%  Default columns in cipher is 7Set the number of columns in the cipher
end

%fid = fopen('cipher.txt','r');		%  Read the Plaintext
%C = fread(fid);
%fclose(fid); 
%C = char(C);
%C = C';

C = y;

sizC = size(C);

R = mod(sizC(2),columns);    % find out how much padding we need

P=0;
if (R>0)
   P = 7 - R;
   for i=1:P                    %  This shouldn't be necessary for a columnar encipherment.
      M = strcat(M,'X');	%  Pad with X's    !!!  - is there a better way?
   end
end


S = sizC(2) + P;	%  This is the size of the padded data (no. of chars). 
rows = S/columns;          %  Number of rows in the matrix.

% T rows and columns in the matrix

for j=1:rows
   for i=1:columns
      C2(i,j) = C((i-1)*rows+j);	%  Make into a matrix (Keep C so we can see it)
      M((j-1)*columns + i) = C((i-1)*rows+j);	%  This is the translation proper
   end
end

x = M;

%fid=fopen('plain.txt','w');
%printf(fid,'%s',M);
%fclose(fid);

