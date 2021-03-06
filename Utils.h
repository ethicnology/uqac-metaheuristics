#include "Tools.h"
int Random(int n);
SMSSDTSolution Shaking(SMSSDTProblem* problem, SMSSDTSolution s, int operation);
SMSSDTSolution FisherYates(SMSSDTSolution s);
void Permute(SMSSDTSolution *s, int cpt);
SMSSDTSolution Swap(SMSSDTSolution s, int pos1, int pos2);
SMSSDTSolution Inversion(SMSSDTSolution s, int pos1, int pos2);
SMSSDTSolution Scramble(SMSSDTSolution s, int pos1, int pos2);
SMSSDTSolution minS(SMSSDTProblem* problem, SMSSDTSolution* s0, SMSSDTSolution* s1);
void StopAndLog(double Start, double Stop, SMSSDTSolution BestSolution, char *ReportFile);
void showLeS(SMSSDTSolution *s);
double RandomValue(double min, double max);
