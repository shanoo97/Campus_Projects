user1=150
user2=200
user3=250
index=0
newprevioushash='0'

password='user';

[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)


[user1,user3]=transfer(user1,user3,100,12345,md5(password)); %basic transaction

user1
user2
user3
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)
[user3,user1]=transfer(user3,user1,100,12345,md5(password)); %basic transaction

user1
user2
user3
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)
[user1,user3]=transfer(user1,user3,100,12345,md5(password));
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)
[user1,user3]=transfer(user1,user3,100,12345,md5(password)); % double spend 
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)


%reseting values 
user1=150
user2=200
user3=250 
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)

incorrectpassword='random'

%identity attack : incorrect password 
[user1,user2]=transfer(user1,user2,100,12345,md5(incorrectpassword));
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)

%identity attack : incorrect token id 
[user1,user3]=transfer(user1,user3,100,7860,md5(password));
[newprevioushash,index]=blockchain(user1,user2,user3,index,newprevioushash)



