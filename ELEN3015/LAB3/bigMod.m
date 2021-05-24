function modd = bigMod(p_temp,power,p_modulo)

a=1;

for (p=1:power)
    a = mod(p_temp*a,p_modulo);
end

modd = a;

end

