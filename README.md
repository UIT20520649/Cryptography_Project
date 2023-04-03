# Cryptography_Project
A Fast Image Encryption Scheme Based on AES
## 1. Topic overview

### Abstract
Ngày nay thì việc đăng ký bản quyền và sở hữu trí tuệ rất quan trọng. Đặc biệt là việc bảo vệ các dữ liệu liên quan đến thiết kế dạng hình ảnh, như các bản vẽ thiết kế thời trang, thiết kế logo, bản vẽ xây dựng...Bởi vì việc đăng ký bản quyền cần thời gian xác minh và được lưu ở nhiều nơi nên có thể bị rò rỉ, đánh cắp hoặc sửa đổi. Nên mục tiêu của đồ án này hướng đến việc mã hóa các dữ liệu dạng hình ảnh thông qua mã hóa bất đối xứng AES. 

### Scenario
|||
|--|--|
||<img  src="https://scontent.fsgn19-1.fna.fbcdn.net/v/t1.15752-9/278932416_400555248583343_7070883332294020837_n.png?_nc_cat=102&ccb=1-7&_nc_sid=ae9488&_nc_ohc=divOK1o8-2IAX9INx2l&_nc_ht=scontent.fsgn19-1.fna&oh=03_AdQMIubbTy8GRYVPuRf_lor-hX4kH9SnqWj5LLyqOzmpGg&oe=6452398C">|


|Suject| Description |
|------|-----|
| Tài sản cần bảo vệ | Dữ liệu dạng hình ảnh về các thiết kế |
| Các bên liên quan | Người đăng ký bản quyền và sở hữu trí tuệ
||Tổ chức tiếp nhận và thẩm định đơn xin đăng ký bản quyền (ví dụ Cục sở hữu trí tuệ Việt Nam)
| Security Goals | Bảo đảm tính bí mật, toàn vẹn, sẵn sàng của bản thiết kế |

## 2. Solution
<img src="https://scontent.fsgn19-1.fna.fbcdn.net/v/t1.15752-9/337910498_1731539320616596_2727062013634325420_n.png?_nc_cat=105&ccb=1-7&_nc_sid=ae9488&_nc_ohc=D3f01Y8dQTIAX9836kK&_nc_oc=AQlQhL9cfX_lC6pct6p8uOgvltskLUc4XHwPn_cQfBkkvsVuJg4rVTkvnPxWUvBcn4M&_nc_ht=scontent.fsgn19-1.fna&oh=03_AdQth76AVP2HMfJnSFdgEh43VlHagWMXLZDXsdWnBFqTYQ&oe=64522623">

## 3. Implementation Plan
Trong quá trình mã hóa hình ảnh AES, hình ảnh được chia thành các khối 128 bit, mỗi khối được mã hóa bằng cách sử dụng một khóa đối xứng. Khóa này được tạo ra bằng cách sử dụng một thuật toán tạo khóa, chẳng hạn như PBKDF2 hoặc scrypt. Khóa đối xứng được sử dụng để thay đổi các bit trong các khối hình ảnh, làm cho chúng trở nên khó đọc được.

Quá trình mã hóa hình ảnh bằng AES được thực hiện qua 10 vòng lặp. Mỗi vòng lặp bao gồm các bước: SubBytes, ShiftRows, MixColumns và AddRoundKey. Các bước này đảm bảo rằng mỗi khối hình ảnh được mã hóa một cách an toàn và khó phá hủy.

Sau khi hoàn thành quá trình mã hóa, hình ảnh đã được mã hóa sẽ trở thành một loạt các khối 128 bit không thể đọc được. Để đọc lại hình ảnh, quá trình giải mã được thực hiện bằng cách sử dụng khóa đối xứng để thực hiện các bước ngược lại, giải mã các khối và khôi phục hình ảnh ban đầu.


<img src="https://scontent.fsgn5-2.fna.fbcdn.net/v/t1.15752-9/337818948_1440696633003735_5796909086995180570_n.png?_nc_cat=105&ccb=1-7&_nc_sid=ae9488&_nc_ohc=c56uWkE4OkgAX-i5fiH&_nc_ht=scontent.fsgn5-2.fna&oh=03_AdQWEeP6XyXDGhQ2DZ9OCGqAFnTom5eIlSj8WtzIk6T3Qg&oe=6450F8BF">

### Các bước của quá trình mã hóa:
Bước 1: Khởi tạo IV. Mỗi IV khác nhau ứng với một kết quả plain image khác nhau. Tạo một giá trị x0 bằng phương pháp pseudo-random (hàm rand() trong MATLAB). Giá trị này là giá trị khởi tạo của tent map (1). Lập lại (1) 16 lần lấy được 16 state, ký hiệu x1, x2,…, x16.

F(x) = {2x với 0 < x < 0.5; 2(1 – x) với 0.5 < x < 1} (1)

Sau đó, chuyển xi – s thành giá trị nguyên theo (2), ký hiệu Xi, i = 1, 2, 3,…, 16. Giá trị của IV = [X1X2…X16].

Xi = floor(10^4 xi) mod 256 (2)

Với floor(x) trả về giá trị nguyên lớn nhất nhỏ hơn x

Bước 2: Với block P1, dùng (3) để mã hóa.

C1 = AESe(K, IV XOR P1) (3)

Bước 3: Với các block Pi còn lại, dùng (4) để mã hóa.

Ci = AESe(K, Ci-1 XOR Pi), i = 2,…, n

### Các bước của quá trình giải mã:
Bước 1: Lấy IV là hình ảnh sau mã hóa C.

Bước 2: Với  block C1, dùng (5) để giải mã.

P1 = AESd(K, C1) XOR IV (5)

Bước 3: Với các block Ci còn lại, dùng (6) để mã hóa.

Pi = AESd(K, Ci) XOR Ci-n, i = 2,…, n

Kết hợp {Pi, i = 1, 2,…, n} thành hình ảnh kích thước MxN, ta thu được hình ảnh.

### Tools and resources
| Tool | SPECIFICATION |
| -------- | -------- |
| Pycryto | Use for algorithm | 
| Python | Programming Language |
| Microsoft SQL| Database|
| Git | Control Project |
| Flash | Python Framework |

| Task | Trần Đinh Huy | Huỳnh Lê Phương Nghi |
|------|---------------|----------------------|
| Tìm đề tài | x | x |
| Trình bày | x | x |
| Viết báo cáo |  | x |
| Làm power point| | x |
| Demo | |  |
