# Cryptography_Project
A Fast Image Encryption Scheme Based on AES
## 1. Topic overview

### Abstract
Ngày nay thì việc đăng ký bản quyền và sở hữu trí tuệ rất quan trọng. Đặc biệt là việc bảo vệ các dữ liệu liên quan đến thiết kế dạng hình ảnh, như các bản vẽ thiết kế thời trang, thiết kế logo, bản vẽ xây dựng...Bởi vì việc đăng ký bản quyền cần thời gian xác minh và được lưu ở nhiều nơi nên có thể bị rò rỉ, đánh cắp hoặc sửa đổi. Nên mục tiêu của đồ án này hướng đến việc mã hóa các dữ liệu dạng hình ảnh thông qua mã hóa bất đối xứng AES. 

### Scenario
|Suject| Description |
|------|-----|
| Tài sản cần bảo vệ | Dữ liệu dạng hình ảnh về các thiết kế |
| Các bên liên quan | Người đăng ký bản quyền và sở hữu trí tuệ
||Tổ chức tiếp nhận và thẩm định đơn xin đăng ký bản quyền (ví dụ Cục sở hữu trí tuệ Việt Nam)
| Security Goals | Bảo đảm tính bí mật, toàn vẹn, sẵn sàng của bản thiết kế |

## 2. Solution
Trong quá trình mã hóa hình ảnh AES, hình ảnh được chia thành các khối 128 bit, mỗi khối được mã hóa bằng cách sử dụng một khóa đối xứng. Khóa này được tạo ra bằng cách sử dụng một thuật toán tạo khóa, chẳng hạn như PBKDF2 hoặc scrypt. Khóa đối xứng được sử dụng để thay đổi các bit trong các khối hình ảnh, làm cho chúng trở nên khó đọc được.

Quá trình mã hóa hình ảnh bằng AES được thực hiện qua 10 vòng lặp. Mỗi vòng lặp bao gồm các bước: SubBytes, ShiftRows, MixColumns và AddRoundKey. Các bước này đảm bảo rằng mỗi khối hình ảnh được mã hóa một cách an toàn và khó phá hủy.

Sau khi hoàn thành quá trình mã hóa, hình ảnh đã được mã hóa sẽ trở thành một loạt các khối 128 bit không thể đọc được. Để đọc lại hình ảnh, quá trình giải mã được thực hiện bằng cách sử dụng khóa đối xứng để thực hiện các bước ngược lại, giải mã các khối và khôi phục hình ảnh ban đầu.


<img src="https://scontent.fsgn5-2.fna.fbcdn.net/v/t1.15752-9/337818948_1440696633003735_5796909086995180570_n.png?_nc_cat=105&ccb=1-7&_nc_sid=ae9488&_nc_ohc=c56uWkE4OkgAX-i5fiH&_nc_ht=scontent.fsgn5-2.fna&oh=03_AdQWEeP6XyXDGhQ2DZ9OCGqAFnTom5eIlSj8WtzIk6T3Qg&oe=6450F8BF">


### Tools and resources
| Tool | SPECIFICATION |
| -------- | -------- |
| Pycryto | Use for algorithm | 
| Python | Programming Language |
| Microsoft SQL| Database|
| Git | Control Project |

## 3. Implementation Plan
Hệ thống bảo mật hình ảnh dựa trên AES
AES (Advanced Encryption Standard) là một thuât toán mã hóa khối. Độ dài mỗi khối (block) là 128 bit, độ dài mỗi key là 128 bit, 192 bit hoặc 256 bit. Trên máy tính thông thường, AES có thể được thực hiện một cách nhanh chóng thông quá phương pháp look-up table. Từ đó áp dụng cho mã hóa hình ảnh.
Cho hình ảnh ban đầu (plain image) _**P**_ là hình ảnh hệ 8 bit có kích thước _MxN_. Chia nhỏ _**P**_ thành _n_ khối nhỏ có kích thước 16 byte (128 bit). Ta có _n = ceil(MN/16)_, với ceil(x) trả về giá trị nguyên nhỏ nhất lớn hơn x. Các block được ký hiệu \[_**P**_i_\], với _i_ = 1, 2, 3,…,_n_. Những byte thừa của block thứ n  được điền bằng 0. Mô hình của hệ thống được biểu diễn ở hình bên.


<img src="https://scontent.fsgn5-2.fna.fbcdn.net/v/t1.15752-9/337818948_1440696633003735_5796909086995180570_n.png?_nc_cat=105&ccb=1-7&_nc_sid=ae9488&_nc_ohc=c56uWkE4OkgAX-i5fiH&_nc_ht=scontent.fsgn5-2.fna&oh=03_AdQWEeP6XyXDGhQ2DZ9OCGqAFnTom5eIlSj8WtzIk6T3Qg&oe=6450F8BF">


Ở hình bên, ta có _**IV**_ với độ dài 128 bit. Ở đây, IV được lấy thông qua chaotic systems. Ở đây, dùng tent map để tạo _**IV**_. Với mỗi quá trình mã hóa, hệ thống mã hóa dùng _**IV**_ khác nhau. _**IV**_ không phải là thông tin ẩn. Cả _**IV**_ và hình ảnh sau mã hóa _**C**_ đều được chuyển đến người nhận qua các kênh công khai. AES_e ký hiệu cho quá trình mã hóa của AES; AES_d ký hiệu cho quá trình giải mã của AES; \[_**C**_i_\], với i = 1, 2,…,_n_ ký hiệu cho mỗi block nhỏ của ảnh sau mã hóa _**C**_. _**K**_ là key ẩn, ở đây dùng key có độ dài 128 bit.

Các bước của quá trình mã hóa:
Bước 1: Khởi tạo _**IV**_. Mỗi _**IV**_ khác nhau ứng với một kết quả plain image khác nhau. Tạo một giá trị x_0 bằng phương pháp pseudo-random (hàm _rand()_ trong MATLAB). Giá trị này là giá trị khởi tạo của tent map (1). Lập lại (1) 16 lần lấy được 16 state, ký hiệu x_i, với i 1, 2,..., 16.

	F(x) = {2x với 0 < x < 0.5; 2(1 – x) với 0.5 < x < 1} (1)
	
Sau đó, chuyển x_i – s thành giá trị nguyên theo (2), ký hiệu X_i, i = 1, 2, 3,…, 16. Giá trị của _**IV**_ = _[X1X2…X16]_.

	X_i = floor(10^4 x_i) mod 256 (2)
	
	Với floor(x) trả về giá trị nguyên lớn nhất nhỏ hơn x.
	
Bước 2: Với block \[_**P**_1_\], dùng (3) để mã hóa.

	\[_**C**_1_\] = AES_e(_**K**_, _**IV**_ XOR \[_**P**_1_\]) (3)
	
Bước 3: Với các block \[_**P**_i_\] còn lại, dùng (4) để mã hóa.

	\[_**C**_i_\] = AES_e(_**K**_, \[_**C**_i - 1_\] XOR \[_**P**_i_\]), i = 2,…,_n_

Các bước của quá trình giải mã:
Bước 1: Lấy _**IV**_ và hình ảnh sau mã hóa _**C**_ thông qua các kênh công khai.
Bước 2: Với  block \[_**C**_1_\], dùng (5) để giải mã.

	\[_**P**_1_\] = AES_d(_**K**_, \[_**C**_1_\]) XOR _**IV**_ (5)
	
Bước 3: Với các block Ci còn lại, dùng (6) để mã hóa.

	\[_**P**_i_\] = AES_d(_**K**_, \[_**C**_i_\]) XOR \[_**P**_i - 1_\], i = 2,…,_n_
	
Kết hợp {\[_**P**_i_\], i = 1, 2,…,_n_} thành hình ảnh kích thước _MxN_, ta thu được hình ảnh.
