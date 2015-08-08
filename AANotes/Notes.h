
/*
STRINGS
***How to take in a line as input:
string line; getline(cin, line);

***Get character at index of string:
str.at(index)

***Convert int to string:(only C++11)
to_string(n)

***Append to string
str.append("string");

***Convert string to int or long: (only C++11)
int num = stoi(str);
long num = stol(str);

***Iterate over a string:
getline(cin, line);
stringstream ss; ss.str(line);
int a;
while (ss >> a){
  printf("%d ", a);
}

**Convert character to lower/uppercase
tolower('A'); // returns 'a'
toupper('a'); // returns 'A'

**String equals ignore case:
bool iequals(const string& a, const string& b)
{
  unsigned int sz = a.size();
  if (b.size() != sz)
    return false;
  for (unsigned int i = 0; i < sz; ++i)
    if (tolower(a[i]) != tolower(b[i]))
      return false;
  return true;
}



CHARACTER
***How to check is character is a digit:
isdigit(ch)

***How to check if character is a letter:
isalpha(ch)



SORTING
***Sort in descending order:
sort(points.rbegin(), points.rend());

***Sort with custom comparator method (see BrightLights for example)
sort(vec.begin(), vec.end(), compMethod);

bool compMethod(ii a, ii b){ //example comparator method
   return a.second < b.second;
}


MAP
***Iterating over a map. (see BrightLights for example)
map<string, int> m
for (map <string, int> >::iterator it = m.begin(); it != m.end(); ++it){
}

SUBSTRINGS
***Print all substrings of a set
for (int i = 1; i < (1 << N); ++i) {
  for (int j = 0; j < N; ++j) {
    if(i & (1<<j)){
      printf("%d", S[j]);
  }
}

}

DATA TYPE RANGES
int
–2,147,483,648 to 2,147,483,647 (-2.14*10^9 to 2.14*10^9)
long long
–9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (-9.2 *10^18 to 9.2*10^18)
unsigned long long
0 to 18,446,744,073,709,551,615 (0 to 1.8*10^19)
*/