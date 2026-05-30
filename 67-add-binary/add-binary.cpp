class Solution {
public:
    string addBinary(string a, string b) {
    string res;
    int cry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0 || cry) {
      if (i >= 0)
        cry += a[i--] - '0';
      if (j >= 0)
        cry += b[j--] - '0';
      res += cry % 2 + '0';
      cry /= 2;
    }
    reverse(begin(res), end(res));
    return res;
    }
};