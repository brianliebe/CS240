#ifndef ANT_H
#define ANT_H

class Ant {
	private:
		int id;
		int x;
		int y;
		int experience;
	public:
		Ant(int);
		void move();
		Ant * fight(Ant * a);
		inline int getID() {
			return id;
		}
		inline int getX() {
			return x;
		}
		inline int getY() {
			return y;
		}
		inline int getExp() {
			return experience;
		}
		inline void setExp(int exp) {
			experience = exp;
		}
};

#endif
