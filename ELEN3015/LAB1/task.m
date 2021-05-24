text = readfile('sampletext.txt');
text = strip(text);
freq = freqget(text);
stdfreq = [ 0.0749    0.0129    0.0354    0.0362    0.1400    0.0218    0.0174 ... %  abcdefg
         0.0422    0.0665    0.0027    0.0047    0.0357    0.0339    0.0674 ... %  hijklmn
         0.0737    0.0243    0.0026    0.0614    0.0695    0.0985    0.0300 ... %  opqrstu
         0.0116    0.0169    0.0028    0.0164    0.0004 ];                      %  vwxyz

