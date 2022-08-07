#include "loan.h"

#include "loan.h"
#include <math.h>
#include<array>
#include<iomanip>

loan::loan()
{

}
loan::loan(double debt, int years, int paymentsPerYear, double interest)
{
    _debt = debt;
    _years = years;
    _paymentsPerYear = paymentsPerYear;
    _interestRate = (interest / _paymentsPerYear);

}

void loan::setDebt(double debt) {
    _debt = debt;
}

double loan::getDebt() const {
    return _debt;
}

void loan::setYears(int years) {
    _years = years;
}

int loan::getYears() const {
    return _years;
}

void loan::setInterestRate(double rate)
{

    _interestRate = (rate / _paymentsPerYear);
}

void loan::setInterestMonthlyToTermin(double interestMonthly)
{
    _interestRate = (pow((1 + interestMonthly), 12) - 1) / _paymentsPerYear;


}

double loan::interestYearlyToMonthly(double interstYealy) const
{

    double interestRate = pow((1 + interstYealy), (1 / 12)) - 1;

    return interestRate;

}

double loan::getInterestRate() const {
    return _interestRate;
}

void loan::setPaymentsPerYear(int paymentsPerYear) {
    _paymentsPerYear = paymentsPerYear;
}

int loan::getPaymentsPerYear() const {
    return _paymentsPerYear;
}

//  y= debt*interest / (1-(1+interest)^-antal terminal)
double loan::totalInterest() const
{
    return totalPayment() - _debt;

}

double loan::paymentPerTerminal() const
{
    double interestTerm = pow((1 + getInterestRate()), -(_paymentsPerYear * _years));


    double ydelse;
    ydelse = _debt * getInterestRate() / (1 - interestTerm);

    return ydelse;
}

double loan::totalPayment() const
{
    // Ydelse ganges med antal ydelser
    return paymentPerTerminal() * (_years * _paymentsPerYear);
}

double loan::totalInterestTaxDeducted(double taxDeductionRate) const
{
    // beregning fradrag
    double taxDeducted = totalInterest() * (taxDeductionRate / 100);

    // substract fradrag fra den totale reneten
    return totalInterest() - taxDeducted;
}

// function return pionter to an array
double* loan::getPaymentsArray()
{
    int size = _paymentsPerYear * _years;
    double* payments = new double[size];

    for (int i = 0; i < size; ++i)
        payments[i] = paymentPerTerminal();

    return payments;

}


// Output the periodical payments with unpaid balance , paid interest
//and repayment of each payment to stream object ost
void loan::outputPeriodicalPayments(std::ostream& ost, loan& l) const
{
    int size = _paymentsPerYear * _years;

    // creat a pionter then we assign it to the function array
    double* vPtr = l.getPaymentsArray();

    double total = totalPayment(),
        paidInterest = 0,
        principal = 0,
        finalInterest = 0,
        debtLoop = _debt;


    cout << "\n***| nr.|\t Debt+Interest  |    Payment   |    Principal   |    Interst  |***\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; ++i)
    {
        //paid interest. We multiply the interest with debt then we add
        //the value to the deptloop. we have to substract every payment from the deptloop aswell.
        //eks. 100kr. debt and 10% interest. paid interest
        // every termin is 10 -->21--33,1 --> etc..

        paidInterest = debtLoop * _interestRate;
        debtLoop += paidInterest;
        debtLoop -= vPtr[i];
        principal = vPtr[i] - paidInterest;
        finalInterest = vPtr[i] - principal;



        // cout<<setw(20);
        ost << "***| " << i + 1 << setw(21) <<
            right << setprecision(8) <<
            total << setw(20) << right <<
            vPtr[i] << setw(18) << right <<
            principal << setw(19) << right <<
            finalInterest;
        ost << endl;

        //unpaid total
        total -= vPtr[i];

    }

    //avoid memory leak by deleting
    delete[] vPtr;
}









