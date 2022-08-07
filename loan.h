
#include <iostream>
#include <array>

using namespace std;

class loan {
public:

    loan();

    // initialisere Loan
    loan(double debt, int years, int paymentsPerYear,
        double interestRate);

    // Returns the number of years the loan lasts
    int getYears() const;
    void setYears(int years);

    // Amount of payments per year ( terminer )
    int getPaymentsPerYear() const;
    void setPaymentsPerYear(int paymentsPerYear);

    // Debt
    double getDebt() const;
    void setDebt(double debt);

    // Rente
    double getInterestRate() const;
    void setInterestRate(double rate);

    // convert the interest  from monthly to yearly
    void setInterestMonthlyToTermin(double interestMonthly);

    // convert the interest from yearly to monthly
    double interestYearlyToMonthly(double interstYealy) const;

    // Calculate each payment per termin
    double paymentPerTerminal() const;

    // Calculate the total interest of a loan for all the years
    double totalInterest() const;

    // Calculate the total repayment of a loan including the interests
    double totalPayment() const;

    // Calculate the total net interest of a loan after tax refund
    double totalInterestTaxDeducted(double taxDeductionRate)
        const;

    // function array, where we return a pointer
    double* getPaymentsArray();

    // Output the periodical payments with unpaid balance , paid interest
    //and repayment of each payment to stream object ost
    void outputPeriodicalPayments(std::ostream& ost, loan& l) const;


private:
    double _debt, _interestRate;
    int _years;  int _paymentsPerYear;


};




