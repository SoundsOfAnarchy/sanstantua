#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int to_digit(char* str) {
	int i = 0;
	int val = 0;
	while (str[i] != '\0') {
		val = val * 10 + (str[i] - '0');
		++i;
	}
	return val;
}

int main(int argc, char* argv[]) {

	if (argc == 2) {
		int level = to_digit(argv[1]);
		int height = 0;
		int level_height = 0;
		int current_height = 0;
		int narost = 0;
		int stars = 0;
		int max_stars = 0;
		for (int i = 0; i < level; ++i) {
			level_height = i + 3;
			if (i != 0) {
				int diff = (i + 1) / 2;
				narost = narost + (diff + 1) * 2;
			}
			for (int j = 0; j < level_height; ++j, ++current_height) {
				max_stars = (current_height * 2 + 1) + narost;
			}
		}

		current_height = 0;
		narost = 0;
		int door_width = 0;
		for (int i = 0; i < level; ++i) {
			level_height = i + 3;
			if (i != 0) {
				int diff = (i + 1) / 2;
				narost = narost + (diff + 1) * 2;
			}
			for (int j = 0; j < level_height; ++j, ++current_height) {
				stars = (current_height * 2 + 1) + narost;
				for (int k = 0; k < (max_stars / 2) - stars / 2; k++) {
					write(1, " ", 1);
				}
				write(1, "/", 1);
				if ((i == level - 1) && j >= (2 + (level - 1) % 2)) {
					if (level % 2) {
						door_width = level;
					} else {
						door_width = level - 1;
					}
					for (int k = 0; k < stars; k++) {
						if ((door_width >= 5) && (k == (stars / 2 + door_width / 2) - 1) && (j == (level_height - 1) - door_width / 2)) {
							write(1, "$", 1);
						} else if ((k >= stars / 2 - door_width / 2) && (k <= stars / 2 + door_width / 2)) {
							write(1, "|", 1);
						} else {
							write(1, "*", 1);
						}
					}
				} else {
					for (int k = 0; k < stars; k++) {
						write(1, "*", 1);
					}
				}
				write(1, "\\\n", 2);
			}
		}
	}
	return 0;
}