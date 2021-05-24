function [a,b] = transfer(a,b,value,hash,pass)

if pass== 'EE11CBB19052E40B07AAC0CA060C23EE' 


hash=md5(hash);
token_id =md5(12345);
if token_id == hash;
    
 if a-value >=0 
     a=a-value 
     b=b+value

 else disp('insufficient funds')
 end 
else disp('incorrect transaction id')
end
else disp('incorrect password; user not identified')
end
pause(1);
end