int j = 0;
int n = bits.size();
while (j < n) {
     if (bits[j] && ++j == (n - 1))
     
        return false;
    j++;
}

return true;