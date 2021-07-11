/**
 * @file salta.cpp
 *
 * @version 01.01 2020-11-11
 *
 * @brief https://training.olinfo.it/#/task/salta/statement
 *
 * @ingroup salta
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

// Variabiles
int N, n, next_;
vector <int> prossimo;
vector <bool> gia_passato;

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
#ifndef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> N;
    prossimo.resize(N + 1);
    gia_passato.resize(N + 1, false);
    next_ = 1;
    n = 0;

    for (int i = 0; i < N; ++i)
        cin >> prossimo[i + 1];

    while (!gia_passato[next_])
    {
        gia_passato[next_] = true;
        next_ = (next_ + prossimo[next_ ]) % N + 1;
        ++n;
#ifdef DEBUG
        cout << "Next: " << next_ << endl;
#endif // DEBUG
    }

    // Output
    cout << N - n << endl;
    for (int i = 1; i < N + 1; ++i)
    {
        if (!gia_passato[i])
            cout << i << " ";
    }
    cout << endl;

    // End
    return 0;
}
