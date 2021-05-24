/*  
	The RSA3 class implements the RSA algorithm using
	Java's BigInteger methods.

	Copyright (c) G.D.Agnew 2001

*/

import java.math.BigInteger;
import java.util.Random;
class RSA3
{


//  Define the objects to be used: all of these have the same meaning
//  as the symbols used in the class notes on RSA:


	static Random rr = new Random(this(System.currentTimeMillis());	//  Random no generator for later
	static BigInteger p = new BigInteger(512,10,rr);
	static BigInteger q = new BigInteger(512,10,rr);
	static BigInteger n = new BigInteger("1");	//  Will change later

	static BigInteger phi = new BigInteger("1");
	static BigInteger e = new BigInteger("1");
	static BigInteger d = new BigInteger("1");

	static BigInteger M = new BigInteger("1");	//  Message text
	static BigInteger C = new BigInteger("1");	//  ciphertext
	static BigInteger M2 = new BigInteger("1");	//  Recovered message text
	static BigInteger a,b,c = new BigInteger("1");	//  Intermediate variables

	static BigInteger ONE = new BigInteger("1");
	static BigInteger ZERO = new BigInteger("0");



    public static void main(String[] args) {
  


    String s = new String();
	System.in.read(s);
	
	System.out.println("KEY GENERATION:");
	System.out.println("Generating random prime p:");

//  Two large random numbers p and q are generated. This is done
//  using the BigInteger(,,) function described here:
//
//	BigInteger(int bitLength,
//		int certainty,
//		Random rnd)
//     Constructs a randomly generated positive BigInteger that is probably
//     prime, with the specified bitLength.

	p = new BigInteger(512,10,rr);
	System.out.println("  p = "+p);

	System.out.println("Generating random prime q:");
	q = new BigInteger(512,10,rr);
	System.out.println("  q = "+q);

	System.out.println("Calculating product n:");
//	Find the product of p and q:   n = p*q:
	n = p.multiply(q);
	System.out.println("  n = "+n);

// Calculate (p-1):
	p = p.subtract(ONE);
// Calculate (q-1):
	q = q.subtract(ONE);

//  Calculate (p-1)(q-1):
	phi = p.multiply(q);
	System.out.println("  (p-1)(q-1) = "+phi);


//  The method below randomly selects and encryption key e using
//  BigInteger(). This key must be relatively prime to phi: relative
//  primeness is easily tested using the gcd function (see below).
//  If gcd returns 1 then they ARE relatively prime. If it does not
//  return 1, another prospective key must be randomly selected
//  and the gcd test repeated; until the requirement is satisfied.
//  The code below does not implement the while loop required to
//  ensure that the generation & test are repeated until a good
//  value of e is found.
//
//  Description of BigInteger(,) function:
//	BigInteger(int numBits, Random rnd) 
//		Constructs a randomly generated BigInteger, uniformly distributed over
//		the range 0 to (2^numBits - 1), inclusive.
//


	e = new BigInteger(512,rr);
	System.out.println("  Randomly chosen encryption key e = "+e);
	
//      gcd(BigInteger val) 
//             Returns a BigInteger whose value is the greatest
//             common divisor of abs(this) and abs(val).	


	a = e.gcd(phi);	//  Make sure that e and (p-1)(q-1) are relatively prime
	System.out.println("  a (gcd) = "+a);	//  Show gcd outcome. 1 is good
	
//  Find the inverse of e, modulo (p-1)(q-1). This is the decryption
//  key d:
	d = e.modInverse(phi);	
	System.out.println("  Decryption key d = "+d);


	System.out.println("ENCRYPTION:");
//  Generate an arbitrary message M: (normally the message would be a block
//  of bytes representing a binary file). 512 specifies the message size.
//  
//
	M = new BigInteger(1023,rr);
	System.out.println("  Plaintext M =  "+M);

//  Do the encryption:
	C = M.modPow(e,n);
	System.out.println("  Ciphertext C =  "+C);
	

	System.out.println("DECRYPTION:");
//  Do the encryption:
	M2 = C.modPow(d,n);
	System.out.println("  Recovered plaintext M2 =  "+M2);

	
   }
}
