/* declare function find_gcd */ 
int find_gcd(int n1, int n2); 

void reduce_fraction(int *nump,  int *denomp) 
{
  int gcd;   
  gcd = find_gcd(*nump, *denomp);
  *nump = *nump / gcd;
  *denomp = *denomp / gcd;
}
