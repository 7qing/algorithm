class Solution {
public:
    bool isMatch(string s, string p) {
    int s_len = s.size();
    int p_len = p.size();
    int s_idx = 0, p_idx = 0, star_idx = -1, match = 0;

    while (s_idx < s_len) {
        if (p_idx < p_len && (p[p_idx] == '?' || s[s_idx] == p[p_idx])) {
            s_idx++;
            p_idx++;
        }
        else if (p_idx < p_len && p[p_idx] == '*') {
            star_idx = p_idx;
            match = s_idx;
            p_idx++;  
        }
        else if (star_idx != -1) {
            p_idx = star_idx + 1;
            match++;
            s_idx = match;
        }
        else {
            return false;
        }
    }

    while (p_idx < p_len && p[p_idx] == '*') {
        p_idx++;
    }

    return p_idx == p_len;
    }
};