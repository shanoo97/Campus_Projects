function x = encolumn(y,columns)
%
%  function x = encolumn(y,columns)
%
%  Encolumn - columnar transposition cipher
%  Takes text in y and en-colmnizes it (assuming columns columns) into x.
%  
%
%    By   G.D.Agnew  (c) 24/2/2001
%    

if (nargin<2)
   columns = 7;		%  Set default columns to 7.
end

%fid = fopen('plain.txt','r');		%  Read the Plaintext
%M = fread(fid);
%fclose(fid); 
% = char(M);
%M = M';

M = y;

sizM = size(M);

R = mod(sizM(2),columns);    % find out how much padding we need

P=0;
if (R>0)
   P = columns - R;
   for i=1:P
      M = strcat(M,'X');	%  Pad with X's    !!!  - is there a better way?
   end
end


S = sizM(2) + P;	%  This is the size of the padded data (no. of chars). 
rows = S/columns;          %  Number of rows in the matrix.

% T rows and columns in the matrix

for j=1:rows
   for i=1:columns
      C2(i,j) = M((j-1)*columns + i );	%  Make into a matrix (Keep C so we can see it)
      C((i-1)*rows+j) = M((j-1)*columns + i );	%  This is the translation proper
   end
end


x = C;

%fid=fopen('cipher.txt','w');
%fprintf(fid,'%s',C);
%close(fid);

