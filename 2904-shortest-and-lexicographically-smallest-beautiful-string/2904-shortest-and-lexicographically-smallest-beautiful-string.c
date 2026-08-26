char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int bestlen = n + 1 ; 
    int beststart = -1;
    int i , j;
    for (i = 0 ; i < n ; i++){
        int count = 0;
        for (j = i ; j< n ; j++){
            if ( s[j] == '1')
                count++;
            if( count == k){
                int len = j-i + 1 ;
                if(len < bestlen){
                    bestlen = len ;
                    beststart = i ;

                }
                else if (len == bestlen){
                    int cmp = strncmp(s + i , s + beststart , len );
                    if(cmp < 0)
                        beststart = i;
                }
                break;
            }
        }
    }
    if ( beststart == -1)
        return "";
    char* ans = malloc( bestlen + 1);
    strncpy(ans , s + beststart , bestlen);
    ans[bestlen] = '\0' ;
    return ans ; 
}