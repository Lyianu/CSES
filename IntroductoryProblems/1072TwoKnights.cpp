#include <iostream>
#include <cstring>
using namespace std;

// Answer:
// Cmr - 4 * (n - 2) * (n - 1), where m = n^2 and r = 2

// Also:
// when r = 2, Cmr = m * (m - 1) / 2

// Copied from 1071NumberSpiral.cpp:
struct BigNum {
    int data[30];
    int length;
};

BigNum NewBigNum(int);

ostream& operator<<(ostream& os, BigNum bn) {
    if (bn.data[30 - bn.length] < 0) {
        os << '-';
    }
    for (int i = 0; i < bn.length; i++) {
        os << abs(bn.data[30 - bn.length + i]);
    }
    return os;
}

BigNum operator+(BigNum a, BigNum b) {
    BigNum c;
    memset(c.data, 0, sizeof(c.data));
    c.length = max(a.length, b.length);
    for (int i = 0; i < c.length; i++) {
        int bit = 29 - i;
        c.data[bit] = a.data[bit] + b.data[bit] + c.data[bit];
        if (c.data[bit] >= 0) {
            c.data[bit - 1] = c.data[bit] / 10;
            c.data[bit] %= 10;
        } else {
            c.data[bit] += 10;
            a.data[bit-1] -= 1;
        }
    }

    for (int i = 29 - c.length; i < 30; i++) {
        if (c.data[i]) {
            c.length = 30 - i;
            //cout << ' ' << c.length << ' ' << c.data[30-i] << ' ';
            break;
        }
        if (!c.data[i] && i == 29) {
            c.length = 0;
        }
    }

    return c;
}

// positive operands only
BigNum operator*(BigNum a, BigNum b) {
    BigNum c;
    memset(c.data, 0, sizeof(c.data));
    
    // offset
    for (int i = 0; i < b.length; i++) {
        for (int k = 0; k < a.length; k++) {
                c.data[29 - i - k] += a.data[29-k] * b.data[29 - i];
            }
    }

    for (int i = 29; i > 0; i--) {
        while (c.data[i] >= 10) {
            c.data[i - 1] += c.data[i] / 10;
            c.data[i] %= 10;
        }
        if (c.data[i]) {
            c.length = 30 - i;
        }
    }

    // cout << a << " * " << b << " = " << c << endl;
    // cout << "a.length: " << a.length << " b.length: " << b.length << endl;

    // for (int i = 29; i > 20; i--) {
    //     cout << c.data[i] << ' ';
    // }
    // cout << endl;

    return c; 
}

BigNum NewBigNum(int n) {
    BigNum bn;
    memset(bn.data, 0, sizeof(bn.data));
    bn.length = 0;
    while (n) {
        bn.data[29 - bn.length++] = n % 10;
        n /= 10;
    }
    return bn;
}

BigNum operator-(BigNum bn) {
    for (int i = 0; i < bn.length; i++) {
        bn.data[29 - i] = -bn.data[29 - i];
    }
    return bn;
}

BigNum operator-(BigNum a, BigNum b) {
    return a + (-b);
}

// for instance where b == 2
BigNum operator/(BigNum a, int b) {
    int carry = 0;
    BigNum c = NewBigNum(0);
    for (int i = 30 - a.length; i < 30; i++) {
        c.data[i] = (carry + a.data[i]) / b;
        carry = ((carry + a.data[i]) % b) * 10;
    }
    for (int i = 30 - a.length; i < 30; i++) {
        if (c.data[i]) {
            c.length = 30 - i;
            break;
        }
    }
    return c;
}

bool operator==(BigNum a, BigNum b) {
    if (a.length != b.length) {
        return false;
    }
    for (int i = 0; i < a.length; i++) {
        if (a.data[29-i] != b.data[29-i])
            return false;
    }
    return true;
}

BigNum Cn2(int n) {
    n = n * n;
    //cout << "Cnr n: " << n << NewBigNum(n) * NewBigNum(n - 1) / 2 << endl;
    return NewBigNum(n) * NewBigNum(n - 1) / 2;
}

int main()
{
    //cout << NewBigNum(208) * NewBigNum(53) << endl;
    int n;
    cin >> n;

   //cout << Cn2(n) << endl;

    for (int i = 1; i <= n; i++) {
        switch (i) {
            case 1: cout << 0 << endl; break;
            case 2: cout << 6 << endl; break;
            case 3: cout << 28 << endl; break;
            case 4: cout << 96 << endl; break;
            case 5: cout << 252 << endl; break;
            case 6: cout << 550 << endl; break;
        }
        if (i <= 6) continue;
        BigNum mul = NewBigNum(4) * NewBigNum(i - 2);
        mul = mul * NewBigNum(i - 1);
        //cout << "mul: " << mul << endl;
        BigNum ans = Cn2(i) - mul;
        cout << ans << endl;
    }

    return 0;
}