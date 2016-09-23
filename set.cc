#include<iostream>
using namespace std;

template <typename T, int N> class Set
{
public:
	bool on[N] {};//true일 때만 그에 대응하는 배열의 요소가 유효.
	T arr[N];//데이터를 담을 배열

	void insert(T n) {
		if(!is_in(n)) {
			for(int i=0; i<N; i++) {
				if(!on[i]) {
					arr[i] = n;
					on[i] = true;
					break;
				}
			}
		}
	}

	void remove(T n) {
		for(int i=0; i<N; i++) if(on[i] && arr[i] == n) on[i] = false;
	}

	bool is_in(T n) {
		for(int i=0; i<N; i++) if(on[i] && arr[i] == n) return true;
		return false;
	}
	
	template <int N2> 
	Set<T, N> operator&(const Set<T, N2>& r) {
		Set<T, N> s;
		for(int i=0; i<N; i++) 
			if(on[i]) for(int j=0; j<N2; j++) 
				if(r.on[j] && arr[i] == r.arr[j]) s.insert(arr[i]);
		return s;
	}

	template <int N2>
	Set<T, N+N2> operator|(const Set<T, N2>& r) {
		Set<T, N+N2> s;
		for(int i=0; i<N; i++) if(on[i]) s.insert(arr[i]);
		for(int i=0; i<N2; i++) if(r.on[i]) s.insert(r.arr[i]);
		return s;
	}

	template <int N2>
	Set<T, N> operator-(const Set<T, N2>& r) {
		Set<T, N> s;
		for(int i=0; i<N; i++) if(on[i]) s.insert(arr[i]);
		for(int i=0; i<N2; i++) if(r.on[i]) s.remove(r.arr[i]);
		return s;
	}

	friend ostream& operator<<(ostream& o, const Set<T, N>& r) {// const 있어야 함.
		o << '{';
		for(int i=0; i<N; i++) if(r.on[i]) o << r.arr[i] << ',';
		o << "\b }";
		return o;
	}

	Set<T, N> operator!() {
		Set<T, N> s;
		for(int i=0; i<N; i++) s.on[i] = !on[i];
		return s;
	}

	Set<T, N> operator&&(const Set<T, N>& r) {
		Set<T, N> s;
		for(int i=0; i<N; i++) s.on[i] = on[i] && r.on[i];
		return s;
	}
	Set<T, N> operator||(const Set<T, N>& r) {
		Set<T, N> s;
		for(int i=0; i<N; i++) s.on[i] = on[i] || r.on[i];
		return s;
	}
	Set<T, N> operator^(const Set<T, N>& r) {
		Set<T, N> s;
		for(int i=0; i<N; i++) s.on[i] = on[i] ^ r.on[i];
		return s;
	}
		
protected:
};


int main()
{
	Set<int, 5> s1;
	for(int i=0; i<5; i++) s1.insert(i);
	Set<int, 10> s2;
	for(int i=3; i<10; i++) s2.insert(i);
	cout << s1 << " & " << s2 << " = " << (s1 & s2) << endl;
	cout << s1 << " | " << s2 << " = " << (s1 | s2) << endl;
	cout << s1 << " - " << s2 << " = " << (s1 - s2) << endl;
	cout << "s1 = " << s1 << endl;
	s1.remove(3);
	cout << "deleted : " << !s1 << " then " << s1 << endl;
	cout << "undelete : " << (!s1 || s1) << endl;
	
}
