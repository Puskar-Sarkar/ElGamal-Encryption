#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long power_mod(long long base, long long exp, long long mod) {
long long result = 1;
while (exp > 0) {
if (exp % 2 == 1)
result = (result * base) % mod;
exp = exp >> 1;
base = (base * base) % mod;}
return result;}
int main() {
 long long p, g, x, y, k, m, c1, c2, shared_secret;
 printf("Enter a prime number (p): ");
 scanf("%lld", &p);
 printf("Enter the primitive root of p (g): ");
 scanf("%lld", &g);
 printf("Enter the private key (x): ");
 scanf("%lld", &x);
 y = power_mod(g, x, p); // Public key
 printf("Enter the message (m) to be encrypted:");
 scanf("%lld", &m);
 printf("Enter a random integer (k): ");
 scanf("%lld", &k);
 c1 = power_mod(g, k, p);
 shared_secret = power_mod(y, k, p);
 c2 = (shared_secret * m) % p;
 printf("Public key: %lld\n", y);
 printf("Ciphertext: (%lld, %lld)\n", c1, c2);
 shared_secret = power_mod(c1, x, p);
 long long decrypted = (c2 *power_mod(shared_secret, p - 2, p)) % p;
 printf("Decrypted message: %lld\n",decrypted);
 return 0;
}
