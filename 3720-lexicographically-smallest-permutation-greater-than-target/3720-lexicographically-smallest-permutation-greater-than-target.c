char* lexGreaterPermutation(char* s, char* target) {

    int n = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    int i;
    for (i = 0; i < n; i++) {

        int t = target[i] - 'a';

        if (count[t] == 0)
            break;

        count[t]--;
    }
    if (i < n) {

        for (int bigger = target[i] - 'a' + 1;
             bigger < 26;
             bigger++) {
            if (count[bigger] > 0) {
                char* ans = malloc(n + 1);
                for (int j = 0; j < i; j++){
                    ans[j] = target[j];
                }
                ans[i] = 'a' + bigger;
                count[bigger]--;
                int pos = i + 1;
                for (int j = 0; j < 26; j++) {
                    while (count[j] > 0) {
                        ans[pos++] = 'a' + j;
                        count[j]--;
                    }
                }

                ans[n] = '\0';
                return ans;
            }
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        count[target[j] - 'a']++;
        int current = target[j] - 'a';
        for (int bigger = current + 1; bigger < 26; bigger++) {
            if (count[bigger] > 0) {
                char* ans = malloc(n + 1);
                for (int k = 0; k < j; k++)
                    ans[k] = target[k];
                ans[j] = 'a' + bigger;
                count[bigger]--;
                int pos = j + 1;
                for (int k = 0; k < 26; k++) {
                    while (count[k] > 0) {
                        ans[pos++] = 'a' + k;
                        count[k]--;
                    }
                }
                ans[n] = '\0';
                return ans;
            }
        }
    }
    char* ans = malloc(1);
    ans[0] = '\0';
    return ans;
}