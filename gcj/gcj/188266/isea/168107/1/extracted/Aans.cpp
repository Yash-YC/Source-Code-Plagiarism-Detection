#include <cstdio>

const int ans[] = {0, 2, 3, 3, 2, 2, 3, 3, 5, 5, 23, 23, 5, 5, 23, 23, 6, 6, 79, 79, 6, 6, 79, 79, 49, 49, 79, 79, 49, 49, 79, 79, 7, 7, 143, 143, 7, 7, 143, 143, 7, 7, 143, 143, 7, 7, 143, 143, 49, 49, 2207, 2207, 49, 49, 2207, 2207, 49, 49, 2207, 2207, 49, 49, 2207, 2207, 8, 8, 27, 27, 8, 8, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 216, 216, 3879, 3879, 216, 216, 3879, 3879, 1975, 1975, 3879, 3879, 1975, 1975, 3879, 3879, 1001, 1001, 5719, 5719, 1001, 1001, 5719, 5719, 1001, 1001, 5719, 5719, 1001, 1001, 5719, 5719, 47089, 47089, 47089, 47089, 47089, 47089, 47089, 47089, 48769, 48769, 58775, 58775, 48769, 48769, 58775, 58775, 3, 3, 3, 3, 3, 3, 3, 3, 27, 27, 27, 27, 27, 27, 27, 27, 415, 415, 707, 707, 415, 415, 707, 707, 415, 415, 1695, 1695, 415, 415, 1695, 1695, 125, 125, 143, 143, 125, 125, 143, 143, 125, 125, 143, 143, 125, 125, 143, 143, 2753, 2753, 37131, 37131, 2753, 2753, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 4977, 4977, 10089, 10089, 4977, 4977, 10089, 10089, 4977, 4977, 23117, 23117, 4977, 4977, 23117, 23117, 6393, 6393, 35785, 35785, 6393, 6393, 35785, 35785, 6393, 6393, 128821, 128821, 6393, 6393, 128821, 128821, 569669, 569669, 705361, 705361, 569669, 569669, 705361, 705361, 569669, 569669, 705361, 705361, 569669, 569669, 705361, 705361, 7, 7, 13, 13, 7, 7, 13, 13, 7, 7, 23, 23, 7, 7, 23, 23, 44, 44, 79, 79, 44, 44, 79, 79, 49, 49, 79, 79, 49, 49, 79, 79, 7, 7, 167, 167, 7, 7, 167, 167, 7, 7, 7895, 7895, 7, 7, 7895, 7895, 49, 49, 6307, 6307, 49, 49, 6307, 6307, 49, 49, 7895, 7895, 49, 49, 7895, 7895, 97, 97, 219, 219, 97, 97, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 608, 608, 3879, 3879, 608, 608, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 34527, 34527, 48041, 48041, 34527, 34527, 48041, 48041, 34527, 34527, 120407, 120407, 34527, 34527, 120407, 120407, 245035, 245035, 285357, 285357, 245035, 245035, 285357, 285357, 245035, 245035, 5649221, 5649221, 245035, 245035, 5649221, 5649221, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 1033, 1033, 6073, 6073, 1033, 1033, 6073, 6073, 4577, 4577, 6073, 6073, 4577, 4577, 6073, 6073, 1337, 1337, 1337, 1337, 1337, 1337, 1337, 1337, 29913, 29913, 120149, 120149, 29913, 29913, 120149, 120149, 71735, 71735, 711725, 711725, 71735, 71735, 711725, 711725, 218301, 218301, 711725, 711725, 218301, 218301, 711725, 711725, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 9867, 9867, 28099, 28099, 9867, 9867, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 48041, 48041, 48041, 48041, 48041, 48041, 48041, 48041, 246297, 246297, 566879, 566879, 246297, 246297, 566879, 566879, 2662657, 2662657, 4817803, 4817803, 2662657, 2662657, 4817803, 4817803, 8691149, 8691149, 8691149, 8691149, 8691149, 8691149, 8691149, 8691149};

int main()
{
    freopen ("A-large.in", "r", stdin);
    freopen ("out3.txt", "w", stdout);
    
    int t, Case = 1;
    scanf ("%d", &t);
    getchar();
    
    while (t--) {
        int now = 0, num = 0;
        for (char ch = getchar(); ch != '\n'; ch = getchar()) {
            if (ch == ' ') {
                now |= (1 << (num - 2));
                num = 0;
            }
            else 
                num = num * 10 + ch - '0';
        }
        now |= (1 << (num - 2));
        printf ("Case #%d: %d\n", Case++, ans[now]);
    }
    
    return 0;
}