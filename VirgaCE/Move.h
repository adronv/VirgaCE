
#ifndef MOVE_CLASS 
#define MOVE_CLASS

class Move {


	public:

		Move();

		int start_index;
		int end_index;
		int piece_type;
		int capture;
		bool enpassant;
		char castle;
		int promotion;
		int score;


		Move(int st, int en, int pt, int ca, bool enp, char cas, int prom, int scr) {
			start_index = st;
			end_index = en;
			piece_type = pt;
			capture = ca;
			enpassant = enp;
			castle = cas;
			promotion = prom;
			score = scr;

		}

		int move_toInt() const;
		

};

#endif