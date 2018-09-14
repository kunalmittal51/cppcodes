#include <bits/stdc++.h>

using namespace std;

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int count=0;
    string special_characters = "!@#$%^&*()-+";
    int flag[4];
    if(n<6)
    {
        return (6-n);
    }
    else
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            if(password[i]>='a' && password[i]<= 'z')
            {
                flag[0]= 1;
                cout << flag[0] << " hello\n";
            }
            if(password[i]>='A' && password[i]<= 'Z')
            {
                flag[1]=1;
            }
            if(password[i]>='0' && password[i]<='9')
            {
                flag[2]=1;
            }
            int k=0;
            while(special_characters[k] != '\0')
            {
                if(password[i]==special_characters[k])
                {
                    flag[3]=1;
                }
                k++;
            }
        }
        for(int i=0;i<4;i++)
        {
            cout << flag[i] << " ";
            if(flag[i]==0)
            {
                count++;
            }
        }
        return count;
    }
}
int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
