int lengthOfLongestSubstring(char * s){
    int lastIndex[256]; // Track last seen index of each character
    for(int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0; // Start of current substring

    for(int i = 0; s[i] != '\0'; i++){
        unsigned char ch = s[i];

        // If character repeated in current window, move start
        if(lastIndex[ch] >= start){
            start = lastIndex[ch] + 1;
        }

        lastIndex[ch] = i; // Update last seen index
        int len = i - start + 1;
        if(len > maxLen) maxLen = len;
    }

    return maxLen;
}

