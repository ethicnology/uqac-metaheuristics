#include "Utils.h"
using namespace std;

int Random() {
	return  rand() % 15;
}

SMSSDTSolution Shaking(SMSSDTProblem *problem, SMSSDTSolution s){
	SMSSDTSolution s0 = NULL, s1 = NULL, s2 = NULL, s3 = NULL, best = NULL;

	int a = Random(), b = Random(), tmp;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	s0 = FisherYates(s);
	s1 = Swap(s, a, b);
	s2 = Inversion(s, a, b);
	s3 = Scramble(s, a, b);

	best = minS(problem, &s0, &s1);
	best = minS(problem, &best, &s2);
	best = minS(problem, &best, &s3);

	return best;
}

SMSSDTSolution FisherYates(SMSSDTSolution s) {
	int j;
	for (int i = 0; i < sizeof(s.Solution)/sizeof(int); i++) {
		j = Random();
		swap(s.Solution[j], s.Solution[i]);
	}
	return s;
}

void Permute(SMSSDTSolution *s, int cpt) {
	int i;
	for (i = 0; i < cpt; i++) {
		std::next_permutation(s->Solution.begin(), s->Solution.end());
	}
}

SMSSDTSolution Swap(SMSSDTSolution s, int pos1, int pos2) {
	swap(s.Solution[pos1], s.Solution[pos2]);
	return s;
}

SMSSDTSolution Inversion(SMSSDTSolution s, int pos1, int pos2) {
	for (int low = pos1, high = pos2; low < high; low++, high--) {
		swap(s.Solution[low], s.Solution[high]);
	}
	return s;
}

SMSSDTSolution Scramble(SMSSDTSolution s, int pos1, int pos2) {
	int j;
	for (int i = pos1; i < pos2 + 1; i++) {
		j = rand() % ((pos2 + 1) - pos1) + pos1;
		swap(s.Solution[j], s.Solution[i]);
	}
	return s;
}


SMSSDTSolution minS(SMSSDTProblem* problem, SMSSDTSolution* s0, SMSSDTSolution* s1) {
	Tools::Evaluer(problem, *s0);
	Tools::Evaluer(problem, *s1);
	if (s0->getObj() < s1->getObj()) {
		return *s0;
	}
	else return *s1;
}

void StopAndLog(double Start, double Stop, SMSSDTSolution BestSolution, char *ReportFile) {
	double Elapsed;
	Elapsed = (double(Stop) - double(Start)) / CLOCKS_PER_SEC;
	Tools::WriteReportLog(Elapsed, BestSolution, ReportFile);
}

void showLeS(SMSSDTSolution* s) {
	int i;
	cout << "S0 : ";
	for (i = 0; i < s->Solution.size(); i++) {
		cout << s->Solution[i] << " ";
	}
	cout << endl << "TT : ";
	for (i = 0; i < s->TT.size(); i++) {
		cout << s->TT[i] << " ";
	}
	cout << endl << "CT : ";
	for (i = 0; i < s->CT.size(); i++) {
		cout << s->CT[i] << " ";
	}
	cout << endl << "ST : ";
	for (i = 0; i < s->ST.size(); i++) {
		cout << s->ST[i] << " ";
	}
	cout << endl << "Fitness : " << s->getObj() << endl;
}