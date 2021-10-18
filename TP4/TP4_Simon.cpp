#include <iostream>
#include <cstdlib>
#include <ctime>

struct date {
	char jour[9];
	int j;
	int m;
	int a;
};

struct personne {
	char prenom[9];
	char nom[10];
	struct date naissance;
};

struct date initDate(unsigned long long int secondesDp1970) {
	struct date date;
	const int joursParSemaines = 7, t0 = 9;
	char nomJoursParSemaines[joursParSemaines][t0] = { {"Jeudi"}, {"Vendredi"}, {"Samedi"}, {"Dimanche"}, {"Lundi"}, {"Mardi"}, {"Mercredi"} };
	int joursDp1970 = secondesDp1970 / 86400 + 1;
	int anneesDp1970 = (joursDp1970 - 0.5) / 365.25;
	int joursDpActAnnee = joursDp1970 - 0.5 - anneesDp1970 * 365.25;
	bool actAnneeEstBissextile = joursDp1970 - 0.5 - anneesDp1970 * 365.25 == joursDpActAnnee;
	for (int i = 0; i < t0; i++) date.jour[i] = nomJoursParSemaines[(joursDp1970 - 1) % joursParSemaines][i];
	date.a = anneesDp1970 + 1970;
	if (joursDpActAnnee < 31) date.m = 1;
	else if (joursDpActAnnee < 59 + actAnneeEstBissextile) {
		date.m = 2;
		joursDpActAnnee -= 31;
	}
	else if (joursDpActAnnee < 90 + actAnneeEstBissextile) {
		date.m = 3;
		joursDpActAnnee -= 59 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 120 + actAnneeEstBissextile) {
		date.m = 4;
		joursDpActAnnee -= 90 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 151 + actAnneeEstBissextile) {
		date.m = 5;
		joursDpActAnnee -= 120 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 181 + actAnneeEstBissextile) {
		date.m = 6;
		joursDpActAnnee -= 151 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 212 + actAnneeEstBissextile) {
		date.m = 7;
		joursDpActAnnee -= 181 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 243 + actAnneeEstBissextile) {
		date.m = 8;
		joursDpActAnnee -= 212 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 273 + actAnneeEstBissextile) {
		date.m = 9;
		joursDpActAnnee -= 243 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 304 + actAnneeEstBissextile) {
		date.m = 10;
		joursDpActAnnee -= 273 + actAnneeEstBissextile;
	}
	else if (joursDpActAnnee < 334 + actAnneeEstBissextile) {
		date.m = 11;
		joursDpActAnnee -= 304 + actAnneeEstBissextile;
	}
	else {
		date.m = 12;
		joursDpActAnnee -= 334 + actAnneeEstBissextile;
	}
	date.j = joursDpActAnnee + 1;
	return date;
}

bool estAnterieureStructDate(struct date d1, struct date d2) {
	if (d1.a < d2.a) return 1; // <
	else if (d1.a > d2.a) return 0; // >
	else {
		if (d1.m < d2.m) return 1; // <
		else if (d1.m > d2.m) return 0; // >
		else {
			if (d1.j < d2.j) return 1; // <
			else if (d1.j > d2.j) return 0; // >
			else return 0; // ==
		}
	}
}

int echangerStructDate(struct date* T, int a, int b) {
	struct date temp = T[a];
	T[a] = T[b];
	T[b] = temp;
	return 0;
}

struct personne initPersonne(unsigned long long int secondesDp1970) {
	struct personne personne;
	struct date date;
	const int totalPrenoms = 40, totalNoms = 40, t0 = 9, t1 = 10;
	char prenoms[totalPrenoms][t0] = { { "Leo" }, { "Gabriel" }, { "Raphael" }, { "Arthur" }, { "Louis" }, { "Jules" }, { "Adam" }, { "Mael" }, { "Lucas" }, { "Hugo" }, { "Noah" }, { "Liam" }, { "Gabin" }, { "Sacha" }, { "Paul" }, { "Nathan" }, { "Aaron" }, { "Mohamed" }, { "Ethan" }, { "Tom" }, { "Eden" }, { "Leon" }, { "Noe" }, { "Tiago" }, { "Theo" }, { "Isaac" }, { "Marius" }, { "Victor" }, { "Ayden" }, { "Martin" }, { "Nael" }, { "Mathis" }, { "Axel" }, { "Robin" }, { "Timeo" }, { "Enzo" }, { "Marceau" }, { "Valentin" }, { "Nino" }, { "Eliott" } };
	char noms[totalNoms][t1] = { { "Martin" }, { "Bernard" }, { "Thomas" }, { "Petit" }, { "Robert" }, { "Richard" }, { "Durand" }, { "Dubois" }, { "Moreau" }, { "Laurent" }, { "Simon" }, { "Michel" }, { "Lefebvre" }, { "Leroy" }, { "Roux" }, { "David" }, { "Bertrand" }, { "Morel" }, { "Fournier" }, { "Girard" }, { "Bonnet" }, { "Dupont" }, { "Lambert" }, { "Fontaine" }, { "Rousseau" }, { "Vincent" }, { "Muller" }, { "Lefevre" }, { "Faure" }, { "Andre" }, { "Mercier" }, { "Blanc" }, { "Guerin" }, { "Boyer" }, { "Garnier" }, { "Chevalier" }, { "Francois" }, { "Legrand" }, { "Gauthier" }, { "Garcia" } };
	for (int i = 0; i < t0; i++) personne.prenom[i] = prenoms[secondesDp1970 % (totalPrenoms)][i];
	for (int i = 0; i < t1; i++) personne.nom[i] = noms[secondesDp1970 % (totalNoms)][i];
	date = initDate(secondesDp1970);
	personne.naissance = date;
	return personne;
}

int main() {
	const int unsigned t0 = 1000;
	struct date T0[t0] = {};
	int unsigned N;
	std::cout << "N" << std::endl; do std::cin >> N; while (N > t0 - 1);
	srand(time(NULL));
	for (int i = 0; i < N; i++) T0[i] = initDate((unsigned long long int)(rand() * rand() * rand()) % (time(0) + 1));
	
	// 3

	int j, m, a;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	for (int i = 0; i < N; i++) {
		if (T0[i].j == j && T0[i].m == m && T0[i].a == a) {
			std::cout << "oui" << std::endl;
			break;
		}
		else if (!(i + 1 < N)) std::cout << "non" << std::endl;
	}

	// 4

	struct date d1, d2;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d1.j = j, d1.m = m, d1.a = a;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d2.j = j, d2.m = m, d2.a = a;
	if (estAnterieureStructDate(d1, d2)) std::cout << "d1 < d2" << std::endl;
	else std::cout << "d1 >= d2" << std::endl;

	// 5

	for (int i = 1; i < N; i++) {
		if (estAnterieureStructDate(T0[i], T0[i - 1])) {
			echangerStructDate(T0, i, i - 1);
			i -= 2;
		}
	}
	const int t1 = 9;
	char jour[t1] = {};
	std::cout << "jour" << std::endl; std::cin >> jour;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	for (int i = 0; i < t1; i++) d1.jour[i] = jour[i];
	d1.j = j, d1.m = m, d1.a = a;
	T0[N] = d1;
	N++;
	for (int i = 1; i < N; i++) {
		if (estAnterieureStructDate(T0[i], T0[i - 1])) {
			echangerStructDate(T0, i, i - 1);
			i -= 2;
		}
	}

	// 6

	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d1.j = j, d1.m = m, d1.a = a;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d2.j = j, d2.m = m, d2.a = a;
	for (int i = 0; i < N; i++) if (!estAnterieureStructDate(T0[i], d1) && !estAnterieureStructDate(d2, T0[i])) std::cout << T0[i].jour << ' ' << T0[i].j << ' ' << T0[i].m << ' ' << T0[i].a << std::endl;
	
	// 8
	
	const int unsigned t2 = 1000;
	struct personne T2[t2] = {};
	std::cout << "N" << std::endl; do std::cin >> N; while (N > t2);
	srand(time(NULL));
	for (int i = 0; i < N; i++) T2[i] = initPersonne((unsigned long long int)(rand() * rand() * rand()) % (time(0) + 1));

	// 9
	
	for (int i = 0; i < N; i++) std::cout << T2[i].prenom << ' ' << T2[i].nom << ' ' << T2[i].naissance.jour << ' ' << T2[i].naissance.j << ' ' << T2[i].naissance.m << ' ' << T2[i].naissance.a << std::endl;

	// 10

	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d1.j = j, d1.m = m, d1.a = a;
	std::cout << "j" << std::endl; do std::cin >> j; while (j < 1 || j > 31);
	std::cout << "m" << std::endl; do std::cin >> m; while (m < 1 || m > 12);
	std::cout << "a" << std::endl; do std::cin >> a; while (a < 0 || a > 9999);
	d2.j = j, d2.m = m, d2.a = a;
	for (int i = 0; i < N; i++) if (!estAnterieureStructDate(T2[i].naissance, d1) && !estAnterieureStructDate(d2, T2[i].naissance)) std::cout << T2[i].prenom << ' ' << T2[i].nom << ' ' << T2[i].naissance.jour << ' ' << T2[i].naissance.j << ' ' << T2[i].naissance.m << ' ' << T2[i].naissance.a << std::endl;
}