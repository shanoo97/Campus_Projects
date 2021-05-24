function [newprevioushash,index] = blockchain (user1,user2,user3,index,previoushash)

str1 = sprintf('Block = %i \n',index)
str2 = sprintf('Data : \n')
str3 = sprintf('User 1 = %i \n',user1)
str4 = sprintf('User 2 = %i \n',user2)
str5 = sprintf('User 3 = %i \n',user3)
str7 = sprintf('Previous Hash = %s \n\n',previoushash)
hashthis=strcat(str1,str2,str3,str4,str5,str7)
hash=md5(hashthis)
str6 = sprintf('Hash = %s \n',hash)


final=sprintf('%s',str1,str2,str3,str4,str5,str6,str7)

writefile(final,'ledger.txt')
index=index+1
newprevioushash=hash



end
