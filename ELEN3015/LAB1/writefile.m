function writefile(x,y)
%  Puts the contents of a char array x into
%  a file with path and name specified in string y.
%
%      Example:  writefile(mystring,'c:\workdir\readme.txt');
%
%    By   G.D.Agnew  (c) 24/2/2001
%    


fid=fopen(y,'w');
fprintf(fid,'%s',x);
fclose(fid);
