#ifndef TIME_VALUE_OF_MONEY_H_INCLUDED
#define TIME_VALUE_OF_MONEY_H_INCLUDED

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

/*
 * @param: times - period
 * @param: r - simple interest rate
 * @return: value of unit principle
 */
double simple_interest_discrete(const double& times, const double& r){
    double a_t = 1.0;
    a_t = (1.0 + times * r);

    return a_t;
}

/*
 * @param: times - period
 * @param: r - simple discount rate
 * @return: discount value of unit principle
 */
double simple_discount_discrete(const double& times, const double& r){
    double a_t = 1.0;
    a_t = 1.0 / (1.0 + times * r);

    return a_t;
}

/*
 * @param: times - period
 * @param: r - compound interest rate
 * @return: value of unit principle
 */
double compound_interest_discrete(const double& times, const double& r){
    double a_t = 1.0;
    a_t = pow(1.0 + r, times);

    return a_t;
}

/*
 * @param: times - period
 * @param: r - compound discount rate
 * @return: discount value of unit principle
 */
double compound_discount_discrete(const double& times, const double& r){
    double a_t = 1.0;
    a_t = 1.0 / pow(1.0 + r, times);

    return a_t;
}

/*
 * @param: amount - principle
 * @param: times - period
 * @param: r - compound interest rate
 * @return: final value of principle
 */
double compound_interest_fv_discrete(const double& amount, const double& times, const double& r){
    double fv = 1.0;
    fv = amount * compound_interest_discrete(times, r);

    return fv;
}

/*
 * @param: amount - principle
 * @param: times - period
 * @param: r - compound discount rate
 * @return: present value of principle
 */
double compound_discount_pv_discrete(const double& amount, const double& times, const double& r){
    double pv = 1.0;
    pv = amount * compound_discount_discrete(times, r);

    return pv;
}

/*
 * @param: times - peroid
 * @param: r - nominal interest rate
 * @return: real interest rate
 */
double real_rate_discrete(const double& times, const double& r){
    double a_r = 1.0;
    a_r = pow(1.0 + r / times, times) - 1.0;

    return a_r;
}

/*
 * @param: times_flow - time corresponding to cash
 * @param: amounts_flow - cash per period
 * @param: total_times - total period
 * @param: r - (compound) interest rate
 * @return: final value of cash flow
 */
double more_cash_flow_fv_discrete(const vector<double>& times_flow,
                                  const vector<double>& amounts_flow,
                                  const double& total_times,
                                  const double& r){
    double fv = 0.0;
    double t_t = total_times;
    for(int i = 0; i < t_t; i++){
        fv += compound_interest_fv_discrete(amounts_flow[i], t_t - times_flow[i], r);
    }

    return fv;
}

/*
 * @param: times_flow - time corresponding to cash
 * @param: amounts_flow - cash per peirod
 * @param: r - (compound) discount rate
 * @return: present value of cash flow
 */
double more_cash_flow_pv_discrete(const vector<double>& times_flow,
                                  const vector<double>& amounts_flow,
                                  const double& r){
    double pv = 0.0;
    double t_t = amounts_flow.size();
    for(int i = 0; i < t_t; i++){
        pv += compound_discount_pv_discrete(amounts_flow[i], times_flow[i], r);
    }

    return pv;
}

#endif // TIME_VALUE_OF_MONEY_H_INCLUDED
