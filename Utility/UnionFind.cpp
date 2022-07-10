class UnionFind {
 public:
  vector<ll> parent;  // parent[i]��i�̐e
  vector<ll> siz;     //�f�W���̃T�C�Y��\���z��(1�ŏ�����)
  map<ll, vector<ll>>
      group;  //�W�����ƂɊǗ�����(key:�W���̑�\���Avalue:�W���̗v�f�̔z��)
  ll n;       //�v�f��

  //�R���X�g���N�^
  UnionFind(ll n_) : n(n_), parent(n_), siz(n_, 1) {
    //�S�Ă̗v�f�̍������g�ł���Ƃ��ď�����
    for (ll i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  //�f�[�^x�̑�����؂̍����擾(�o�H���k���s��)
  ll root(ll x) {
    if (parent[x] == x) return x;
    return parent[x] = root(
               parent[x]);  //������̒l�͑�������ϐ��̒l�Ȃ̂ŁA�o�H���k�ł���
  }

  // x��y�̖؂𕹍�
  void unite(ll x, ll y) {
    ll rx = root(x);       // x�̍�
    ll ry = root(y);       // y�̍�
    if (rx == ry) return;  //�����؂ɂ��鎞
    //�������W����傫���W���ւƕ���(ry��rx�֕���)
    if (siz[rx] < siz[ry]) swap(rx, ry);
    siz[rx] += siz[ry];
    parent[ry] = rx;  // x��y�������؂ɂȂ�����y�̍�ry��x�̍�rx�ɂ���
  }

  // x��y��������؂��������𔻒�
  bool same(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }

  // x�̑f�W���̃T�C�Y���擾
  ll size(ll x) { return siz[root(x)]; }

  //�f�W�������ꂼ��O���[�v��
  void grouping() {
    //�o�H���k���ɍs��
    REP(i, n) root(i);
    // map�ŊǗ�����(�f�t�H���g�\�z�𗘗p)
    REP(i, n) group[parent[i]].PB(i);
  }

  //�f�W���n���폜���ď�����
  void clear() {
    REP(i, n) { parent[i] = i; }
    siz = vector<ll>(n, 1);
    group.clear();
  }
};