#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct BigNum {
    int data[30];
    int length;
};

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
        c.data[bit] = a.data[bit] + b.data[bit];
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

    //cout << a << " + " << b << " = " << c << endl;

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
        if (c.data[i] > 10) {
            c.data[i - 1] += c.data[i] / 10;
            c.data[i] %= 10;
        }
        if (c.data[i]) {
            c.length = 30 - i;
        }
    }

    //cout << a << " * " << b << " = " << c << endl;

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

// b == 2
int operator%(BigNum a, int b) {
    return a.data[29] % b;
}

// positive only, again
BigNum max(BigNum a, BigNum b) {
    if (a.length > b.length) {
        return a;
    } else if (a.length < b.length) {
        return b;
    }
    return a.data[30 - a.length] > b.data[30 - b.length] ? a : b;
}

typedef long long LL;

int main()
{
    //cout << -1 % 10 << endl;
    //cout << NewBigNum(20) * NewBigNum(20);
    int t;
    cin >> t;

    while (t--) {
        int y_, x_;
        cin >> y_ >> x_;

        BigNum y = NewBigNum(y_);
        BigNum x = NewBigNum(x_);

        // center square
        BigNum number = (max(x, y) - NewBigNum(1)) * (max(x, y) - NewBigNum(1));

        // if x is the bigger one, y decides the outer circle
        if (x == max(x, y)) {
            // numbers goes CCW
            if (x.data[29] % 2) {
                number = NewBigNum(2) * x - y - NewBigNum(1) + number;
            } else {
                // CW
                number = number + y;
            }
        } else {
            // CCW
            if (y % 2) {
                number = x + number;
            } else {
                // CW
                number = NewBigNum(2) * y - x - NewBigNum(1) + number;
            }
        }
        if (y_ == x_) {
            number = number - NewBigNum(1);
        }
        cout << number + NewBigNum(1) << endl;
    }

    return 0;
}