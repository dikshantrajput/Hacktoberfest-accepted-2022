#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

template <typename T>
class matrix
{
public:
  vector<vector<T>> val;
  int n;
  matrix(int s)
  {
    n = s;
    val.resize(n);
    for (int i = 0; i < n; i++)
      val[i].resize(n);
  }
  matrix<T> &operator=(const matrix<T> &b)
  {
    val = b.val;
    n = b.n;
    return *this;
  }
  vector<T> column_multiply(const vector<T> &col)
  {
    int n = col.size();
    vector<T> row(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        row[i] += this->val[i][j] * col[j];
      }
    }
    return row;
  }
  void print()
  {
    rep(i, 0, n)
    {
      rep(j, 0, n)
      {
        cout << val[i][j] << " ";
      }
      cout << endl;
    }
  }
  matrix<T> operator*(const matrix<T> &b) const
  {
    matrix<T> ans(b.n);
    for (int i = 0; i < b.n; i++)
    {
      for (int j = 0; j < b.n; j++)
      {
        for (int k = 0; k < b.n; k++)
        {
          ans.val[i][j] += this->val[i][k] * b.val[k][j];
        }
      }
    }
    return ans;
  }
  matrix<T> identity(int N)
  {
    matrix<T> ans(N);
    for (int i = 0; i < N; i++)
    {
      ans.val[i][i] = 1;
    }

    return ans;
  }
};

namespace Geometry
{
  vector<vector<float>> a = {{40, 40, -50}, {90, 40, -50}, {90, 90, -50}, {40, 90, -50}, {30, 30, 0}, {80, 30, 0}, {80, 80, 0}, {30, 80, 0}};
  vector<vector<float>> colors = {{0.7, 0.4, 0.7}, {0.2, 0.5, 0.3}, {0.2, 0.4, 0.7}, {0.5, 0.4, 0.3}, {0.5, 0.7, 0.2}, {0.2, 0.3, 0.4}};

  void display(vector<vector<float>> a)
  {
		/**
		 * this function displays cube using a vector of vector a as parameter matrix
		 * -> a[i] is the ith vertex
		 * -> a[i][j] is the jth axis of ith vertex
		 * -> this function uses GL_LINE_LOOP to contruct the 6 faces by connecting
		 * 		the corresponding face vertices
		*/
    int i;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glEnd();
    i = 0;
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glVertex3f(a[7][0], a[7][1], a[7][2]);
    glVertex3f(a[4][0], a[4][1], a[4][2]);
    glEnd();
    i = 1;
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    i = 2;
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    i = 4;
    glBegin(GL_LINE_LOOP);
    glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3f(a[2 + i][0], a[2 + i][1], a[2 + i][2]);
    glVertex3f(a[3 + i][0], a[3 + i][1], a[3 + i][2]);
    glEnd();
  }
  void draw_axes()
  {
    glColor3f(0.0, 0.0, 0.0); // Set the color to BLACK
    glBegin(GL_LINES);        // Plotting X-Axis
    glVertex2s(-1000, 0);
    glVertex2s(1000, 0);
    glEnd();
    glBegin(GL_LINES); // Plotting Y-Axis
    glVertex2s(0, -1000);
    glVertex2s(0, 1000);
    glEnd();
  }
  int choice;
  float x, y, z;
  float xo, yo, zo;
  float n1, n2, n3;

  void Main()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_axes();
    display(a);
		// we first create a 4x4 transformation matrix 
    matrix<float> mat(4);
    int d0 = n1 * xo + n2 * yo + n3 * zo;
    int d1 = n1 * x + n2 * y + n3 * z;
    int d = d0 - d1;
    if (choice == 1)
    {
			// transformation matrix for perspective projection
      mat.val = {{d1 - x * n1, -x * n2, -x * n3, x * d0}, {-y * n1, d1 - y * n2, -y * n3, y * d0}, {-z * n1, -z * n2, d1 - z * n3, z * d0}, {0, 0, 0, d1}};
    }
    else
    {
      assert(choice == 2);
			// transformation matrix for parallel projection
      mat.val = {{d + x * n1, x * n2, x * n3, -d0 * x}, {y * n1, d + y * n2, y * n3, -d0 * y}, {z * n1, z * n2, d + z * n3, -d0 * z}, {n1, n2, n3, -d1}};
    }
		// here a2 is the transformed matrix of a
    vector<vector<float>> a2 = a;
    for (auto &i : a2)
    {
      vector<float> col = {i[0], i[1], i[2], 1};
      col = mat.column_multiply(col);
			// now we homogenize the column vector
      i = {col[0] / col[3], col[1] / col[3], col[2] / col[3]};
    }
    display(a2);
    glFlush();
  }
} // namespace Geometry

using namespace Geometry;

int main(int argc, char **argv)
{

  cout << "Enter 1 for Parallel projection" << endl;
  cout << "Enter 2 for Perspective projection" << endl;

  cout << "Your choice : ";

  cin >> choice;

  if (choice == 1)
  {
    cout << "Enter the i,j and k components of vector V: ";
    cin >> x >> y >> z;
    cout << "Enter the co-ordinate (R0) of plane: ";
    cin >> xo >> yo >> zo;
    cout << "Enter the i,j and k components of normal vector N: ";
    cin >> n1 >> n2 >> n3;
  }
  else if (choice == 2)
  {
    cout << "Enter the x,y and z components of center of projection: ";
    cin >> x >> y >> z;
    cout << "Enter the co-ordinate (R0) of plane: ";
    cin >> xo >> yo >> zo;
    cout << "Enter the i,j and k components of normal vector N: ";
    cin >> n1 >> n2 >> n3;
  }
  else
  {
    cout << "Wrong choice" << endl;
    exit(0);
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Projections ");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
  glEnable(GL_DEPTH_TEST);
	// Function that does the job
  glutDisplayFunc(Main);
  glutMainLoop();
}