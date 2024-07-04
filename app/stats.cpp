#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

// Custom rounding function based on column position
double customRound(double value, int decimalPlaces) {
  return round(value * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
}

// [[Rcpp::export]]
DataFrame computeStats(NumericMatrix data, CharacterVector colNames) {
  int n = data.ncol();
  NumericVector n_obs(n), means(n), sds(n), mins(n), q1s(n), medians(n), q3s(n), maxs(n);
  
  for (int i = 0; i < n; i++) {
    NumericVector col = data(_, i);
    int decimalPlaces = ((i == n-1) ? 0 : 2);
    
    n_obs[i] = col.size();
    means[i] = customRound(mean(col), decimalPlaces);
    sds[i] = customRound(sd(col), decimalPlaces);
    mins[i] = customRound(min(col), decimalPlaces);
    medians[i] = customRound(median(col), decimalPlaces);
    maxs[i] = customRound(max(col), decimalPlaces);
    
    arma::vec armaCol = as<arma::vec>(col);
    arma::vec quantiles = {0.25, 0.75};
    arma::vec quantileResults = arma::quantile(armaCol, quantiles);
    
    q1s[i] = customRound(quantileResults(0), decimalPlaces);
    q3s[i] = customRound(quantileResults(1), decimalPlaces);
  }
  
  return DataFrame::create(
    Named("n_obs") = n_obs,
    Named("mean") = means, 
    Named("sd") = sds, 
    Named("min") = mins,
    Named("Q1") = q1s, 
    Named("median") = medians, 
    Named("Q3") = q3s, 
    Named("max") = maxs);
}
