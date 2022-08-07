#include <iostream>
#include "loan.h"
#include<math.h>
#include<ostream>
#include <string>

using namespace std;

int main()
{
    double debt, rente, inputRente, tax;

    int years, paymentsPerYear, valg;
    
    bool checkMe = true, valg1 = true;
    
    loan newLoan;

    while (checkMe)
    {


        // debt, years, payment per year, interest
        cout << "\n\tThe amount of loan = "; cin >> debt;
        newLoan.setDebt(debt);

        cout << "\n\tNumber of years = "; cin >> years;
        newLoan.setYears(years);

        cout << "\n\tNumber payments pr year = "; cin >> paymentsPerYear;
        newLoan.setPaymentsPerYear(paymentsPerYear);

        while (valg1)
        {
            cout << "\nDo you pay with \n\t1.Monthly interest(1)\n\t2.Yearly interest(2)\n";
            cin >> valg;


            if (valg == 1)
            {
                cout << "\nThe monthly fixed interest = "; cin >> inputRente;
                newLoan.setInterestMonthlyToTermin(inputRente / 100);
                valg1 = false;
            }
            else if (valg == 2)
            {
                cout << "\nThe yearly fixed interest = "; cin >> rente;
                newLoan.setInterestRate(rente / 100);
                valg1 = false;
            }
            else
                cout << "\nInput is incorrect. Please try again!!";


        }

        cout << "\n\tPayment per terminal= " << newLoan.paymentPerTerminal();
        cout << "\n\tThe total amount you have to pay it back= " << newLoan.totalPayment();
        cout << "\n\n\tThe tax refund porcent= ";
        cin >> tax;

        cout << "\nThe total interest before tax is " << newLoan.totalInterest() << "\n"

            "The total interest after tax is " << newLoan.totalInterestTaxDeducted(tax);


        cout << "\n\n";

        std::ostream& ost = std::cout;

        newLoan.outputPeriodicalPayments(ost, newLoan);
        cout << endl;
        cout << endl;

        cout << "Would you like to calculate again?\nPress \t1 yes \n\t2 No";
        cout << endl;
        cin >> valg;

        valg != 1 ? checkMe = false : checkMe = true;


        valg = 0;
        valg1 = true;


    }
    return 0;
}
