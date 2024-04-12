#include <Novice.h>
#include <math.h>

//間隔
static const int kRowHeight = 20;
static const int kColumnWidth = 60;

//三次元
struct Vector3
{
	float x, y, z;
};

//加算
static Vector3 Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 result{};
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

//減算
static Vector3 Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 result{};
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

//スカラー倍
static Vector3 Multiply(float scalar, const Vector3& v)
{
	Vector3 result{};
	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;
	return result;
}

//内積
static float Dot(const Vector3& v1, const Vector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//長さ（ノルム）
static float Length(const Vector3& v)
{
	return sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
}

//正規化
static Vector3 Nomalize(const Vector3& v)
{
	float length = Length(v);
	Vector3 result{};
	if (length != 0.0)
	{
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	}
	return result;
}

//コメント
static void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

const char kWindowTitle[] = "LE2B_09_キクチ_ケンタ_提出用課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1 = { 1.0f,3.0f,-5.0f };
	Vector3 v2 = { 4.0f,-1.0f,2.0f };

	float k = 4.0f;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///-----関数を呼ぶ-----///

		//Add関数を呼んでv1とv2の数値を足す
		Vector3 ResultAdd = Add(v1, v2);

		//Subtract関数を呼んでv1とv2の数値を引く
		Vector3 ResultSub = Subtract(v1, v2);

		//Multiply関数を読んでv1にk倍させる
		Vector3 ResultMul = Multiply(k, v1);

		//Dot関数を呼んでv1とv2での内積を計算する
		float ResultDot = Dot(v1, v2);

		//Length関数を呼んでv1の長さを計算する
		float ResultLen = Length(v1);

		//Nomalize関数を呼んでv2を正規化させる
		Vector3 ResultNor = Nomalize(v2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, ResultAdd, " : Add");
		VectorScreenPrintf(0, kRowHeight, ResultSub, " : Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, ResultMul, " : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f : Dot", ResultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f : Length", ResultLen);
		VectorScreenPrintf(0, kRowHeight * 5, ResultNor, " : Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
