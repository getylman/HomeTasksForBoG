#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#define N 105
//#define L 4294967296
#define ll long long









int main() {
	char s[100009];
	scanf("%s", s);
	int B[100] = {};
	int it = 0;
	while(*(s + it) != '\0') {
		if(s[it] == 'm' || s[it] == 'M') {
			B[(int)'M'] ++;
		}
		else if(s[it] == 'd' || s[it] == 'D') {
			B[(int)'D'] ++;
		}
		else if(s[it] == 'c' || s[it] == 'C') {
			B[(int)'C'] ++;
		}
		else if(s[it] == 'l' || s[it] == 'L') {
			B[(int)'L'] ++;
		}
		else if(s[it] == 'x' || s[it] == 'X') {
			B[(int)'X'] ++;
		}
		else if(s[it] == 'v' || s[it] == 'V') {
			B[(int)'V'] ++;
		}
		else if(s[it] == 'i' || s[it] == 'I') {
			B[(int)'I'] ++;
		}
		++ it;
	}
	char S[200] = {};
	it = 0;
	if(B[(int)'M']) {
		if(B[(int)'M'] > 0 && B[(int)'M'] < 4) {
			int y = B[(int)'M'];
			while(y --) {
				S[it ++] = 'M';
			}
			//*********************************
			if(B[(int)'D']) {
				S[it ++] = 'D';
				if(B[(int)'C']) {
					if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
						int y = B[(int)'C'];
						while(y --) {
							S[it ++] = 'C';
						}
						if(B[(int)'L']) {
							S[it ++] = 'L';
							if(B[(int)'X']) {
								if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
									int y = B[(int)'X'];
									while(y --) {
										S[it ++] = 'X';
									}
									if(B[(int)'V']) {
										S[it ++] = 'V';
										if(B[(int)'I']) {
											int o = 0, y = B[(int)'I'];
											while(y -- && o < 3) {
												S[it ++] = 'I';
												o ++;
											}
										}
									}
									else {
										if(B[(int)'I']) {
											int o = 0, y = B[(int)'I'];
											while(y -- && o < 3) {
												S[it ++] = 'I';
												o ++;
											}
										}
									}
								}
								else {
									int y = 3;
									while(y --) {
										S[it ++] = 'X';
									}
									if(B[(int)'I']) {
										S[it ++] = 'I';
										S[it ++] = 'X';
									}
								}
							}
							else if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'C';
						}
						if(B[(int)'X']) {
							S[it ++] = 'X';
							S[it ++] = 'C';
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
					}
				}
				else {
					if(B[(int)'L']) {
						S[it ++] = 'L';
						if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
			}
			else if(B[(int)'C']) {
				if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
					int y = B[(int)'C'];
					while(y --) {
						S[it ++] = 'C';
					}
					if(B[(int)'L']) {
						S[it ++] = 'L';
						if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'C';
					}
					if(B[(int)'X']) {
						S[it ++] = 'X';
						S[it ++] = 'C';
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
				}
			}
			else if(B[(int)'L']) {
				S[it ++] = 'L';
				if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'X']) {
				if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
					int y = B[(int)'X'];
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'I']) {
						S[it ++] = 'I';
						S[it ++] = 'X';
					}
				}
			}
			else if(B[(int)'V']) {
				S[it ++] = 'V';
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'I']) {
				int o = 0, y = B[(int)'I'];
				while(y -- && o < 3) {
					S[it ++] = 'I';
					o ++;
				}
			}
			//************************************
		}
		else {
			int y = 3;
			while(y --) {
				S[it ++] = 'M';
			}
			if(B[(int)'C']) {
				B[(int)'C'] --;
				S[it ++] = 'C';
				S[it ++] = 'M';
				if(B[(int)'L']) {
					S[it ++] = 'L';
					if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'D']) {
				S[it ++] = 'D';
				if(B[(int)'C']) {
					if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
						int y = B[(int)'C'];
						while(y --) {
							S[it ++] = 'C';
						}
						if(B[(int)'L']) {
							S[it ++] = 'L';
							if(B[(int)'X']) {
								if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
									int y = B[(int)'X'];
									while(y --) {
										S[it ++] = 'X';
									}
									if(B[(int)'V']) {
										S[it ++] = 'V';
										if(B[(int)'I']) {
											int o = 0, y = B[(int)'I'];
											while(y -- && o < 3) {
												S[it ++] = 'I';
												o ++;
											}
										}
									}
									else {
										if(B[(int)'I']) {
											int o = 0, y = B[(int)'I'];
											while(y -- && o < 3) {
												S[it ++] = 'I';
												o ++;
											}
										}
									}
								}
								else {
									int y = 3;
									while(y --) {
										S[it ++] = 'X';
									}
									if(B[(int)'I']) {
										S[it ++] = 'I';
										S[it ++] = 'X';
									}
								}
							}
							else if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'C';
						}
						if(B[(int)'X']) {
							S[it ++] = 'X';
							S[it ++] = 'C';
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
					}
				}
				else {
					if(B[(int)'L']) {
						S[it ++] = 'L';
						if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
			}
			else if(B[(int)'C']) {
				if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
					int y = B[(int)'C'];
					while(y --) {
						S[it ++] = 'C';
					}
					if(B[(int)'L']) {
						S[it ++] = 'L';
						if(B[(int)'X']) {
							if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
								int y = B[(int)'X'];
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'V']) {
									S[it ++] = 'V';
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
								else {
									if(B[(int)'I']) {
										int o = 0, y = B[(int)'I'];
										while(y -- && o < 3) {
											S[it ++] = 'I';
											o ++;
										}
									}
								}
							}
							else {
								int y = 3;
								while(y --) {
									S[it ++] = 'X';
								}
								if(B[(int)'I']) {
									S[it ++] = 'I';
									S[it ++] = 'X';
								}
							}
						}
						else if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'C';
					}
					if(B[(int)'X']) {
						S[it ++] = 'X';
						S[it ++] = 'C';
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
				}
			}
			else if(B[(int)'L']) {
				S[it ++] = 'L';
				if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'X']) {
				if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
					int y = B[(int)'X'];
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'I']) {
						S[it ++] = 'I';
						S[it ++] = 'X';
					}
				}
			}
			else if(B[(int)'V']) {
				S[it ++] = 'V';
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'I']) {
				int o = 0, y = B[(int)'I'];
				while(y -- && o < 3) {
					S[it ++] = 'I';
					o ++;
				}
			}
		}
		S[it] = '\0';
		printf("%s", S);
	}//------------------------
	else if(B[(int)'D']) {
		S[it ++] = 'D';
		if(B[(int)'C']) {
			if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
				int y = B[(int)'C'];
				while(y --) {
					S[it ++] = 'C';
				}
				if(B[(int)'L']) {
					S[it ++] = 'L';
					if(B[(int)'X']) {
						if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
							int y = B[(int)'X'];
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'V']) {
								S[it ++] = 'V';
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
							else {
								if(B[(int)'I']) {
									int o = 0, y = B[(int)'I'];
									while(y -- && o < 3) {
										S[it ++] = 'I';
										o ++;
									}
								}
							}
						}
						else {
							int y = 3;
							while(y --) {
								S[it ++] = 'X';
							}
							if(B[(int)'I']) {
								S[it ++] = 'I';
								S[it ++] = 'X';
							}
						}
					}
					else if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else {
				int y = 3;
				while(y --) {
					S[it ++] = 'C';
				}
				if(B[(int)'X']) {
					S[it ++] = 'X';
					S[it ++] = 'C';
					if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
				}
			}
		}
		else {
			if(B[(int)'L']) {
				S[it ++] = 'L';
				if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'X']) {
				if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
					int y = B[(int)'X'];
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'I']) {
						S[it ++] = 'I';
						S[it ++] = 'X';
					}
				}
			}
			else if(B[(int)'V']) {
				S[it ++] = 'V';
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'I']) {
				int o = 0, y = B[(int)'I'];
				while(y -- && o < 3) {
					S[it ++] = 'I';
					o ++;
				}
			}
		}
		S[it] = '\0';
		printf("%s", S);//перепроверить реализацию D
	}//-----------------------
	else if(B[(int)'C']) {
		if(B[(int)'C'] > 0 && B[(int)'C'] < 4) {
			int y = B[(int)'C'];
			while(y --) {
				S[it ++] = 'C';
			}
			if(B[(int)'L']) {
				S[it ++] = 'L';
				if(B[(int)'X']) {
					if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
						int y = B[(int)'X'];
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'V']) {
							S[it ++] = 'V';
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
						else {
							if(B[(int)'I']) {
								int o = 0, y = B[(int)'I'];
								while(y -- && o < 3) {
									S[it ++] = 'I';
									o ++;
								}
							}
						}
					}
					else {
						int y = 3;
						while(y --) {
							S[it ++] = 'X';
						}
						if(B[(int)'I']) {
							S[it ++] = 'I';
							S[it ++] = 'X';
						}
					}
				}
				else if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'X']) {
				if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
					int y = B[(int)'X'];
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'V']) {
						S[it ++] = 'V';
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
					else {
						if(B[(int)'I']) {
							int o = 0, y = B[(int)'I'];
							while(y -- && o < 3) {
								S[it ++] = 'I';
								o ++;
							}
						}
					}
				}
				else {
					int y = 3;
					while(y --) {
						S[it ++] = 'X';
					}
					if(B[(int)'I']) {
						S[it ++] = 'I';
						S[it ++] = 'X';
					}
				}
			}
			else if(B[(int)'V']) {
				S[it ++] = 'V';
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else if(B[(int)'I']) {
				int o = 0, y = B[(int)'I'];
				while(y -- && o < 3) {
					S[it ++] = 'I';
					o ++;
				}
			}
		}
		else {
			int y = 3;
			while(y --) {
				S[it ++] = 'C';
			}
			if(B[(int)'X']) {
				S[it ++] = 'X';
				S[it ++] = 'C';
				if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else {
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
			}
		}
		S[it] = '\0';
		printf("%s", S);
	}//----------------------
	else if(B[(int)'L']) {
		S[it ++] = 'L';
		if(B[(int)'X']) {
			if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
				int y = B[(int)'X'];
				while(y --) {
					S[it ++] = 'X';
				}
				if(B[(int)'V']) {
					S[it ++] = 'V';
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
				else {
					if(B[(int)'I']) {
						int o = 0, y = B[(int)'I'];
						while(y -- && o < 3) {
							S[it ++] = 'I';
							o ++;
						}
					}
				}
			}
			else {
				int y = 3;
				while(y --) {
					S[it ++] = 'X';
				}
				if(B[(int)'I']) {
					S[it ++] = 'I';
					S[it ++] = 'X';
				}
			}
		}
		else if(B[(int)'V']) {
			S[it ++] = 'V';
			if(B[(int)'I']) {
				int o = 0, y = B[(int)'I'];
				while(y -- && o < 3) {
					S[it ++] = 'I';
					o ++;
				}
			}
		}
		else if(B[(int)'I']) {
			int o = 0, y = B[(int)'I'];
			while(y -- && o < 3) {
				S[it ++] = 'I';
				o ++;
			}
		}
		S[it] = '\0';
		printf("%s", S);
	}//--------------------
	else if(B[(int)'X']) {
		if(B[(int)'X'] > 0 && B[(int)'X'] < 4) {
			int y = B[(int)'X'];
			while(y --) {
				S[it ++] = 'X';
			}
			if(B[(int)'V']) {
				S[it ++] = 'V';
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
			else {
				if(B[(int)'I']) {
					int o = 0, y = B[(int)'I'];
					while(y -- && o < 3) {
						S[it ++] = 'I';
						o ++;
					}
				}
			}
		}
		else {
			int y = 3;
			while(y --) {
				S[it ++] = 'X';
			}
			if(B[(int)'I']) {
				S[it ++] = 'I';
				S[it ++] = 'X';
			}
		}
		S[it] = '\0';
		printf("%s", S);
	}//---------------
	else if(B[(int)'V']) {
		S[it ++] = 'V';
		if(B[(int)'I']) {
			int o = 0, y = B[(int)'I'];
			while(y -- && o < 3) {
				S[it ++] = 'I';
				o ++;
			}
		}
		S[it] = '\0';
		printf("%s", S);
	}//--------------
	else if(B[(int)'I']) {
		int o = 0, y = B[(int)'I'];
		while(y -- && o < 3) {
			S[it ++] = 'I';
			o ++;
		}
		S[it] = '\0';
		printf("%s", S);
	}
	return 0;
}
