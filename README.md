# Cryptography_Project
A Fast Image Encryption Scheme Based on AES
## 1. Topic overview

### Abstract
Ngày nay thì việc đăng ký bản quyền và sở hữu trí tuệ rất quan trọng. Đặc biệt là việc bảo vệ các dữ liệu liên quan đến thiết kế dạng hình ảnh, như các bản vẽ thiết kế thời trang, thiết kế logo, bản vẽ xây dựng...Bởi vì việc đăng ký bản quyền cần thời gian xác minh, khi xác minh thì hình ảnh đó được gửi qua nhiều bên và được lưu ở nhiều nơi nên có thể bị rò rỉ, đánh cắp hoặc sửa đổi. Nên mục tiêu của đồ án này hướng đến việc mã hóa các dữ liệu dạng hình ảnh thông qua mã hóa AES. Trong nội bộ cơ quan kiểm định và cấp bằng sở hữu trí tuệ
Ngày nay thì việc đăng ký bản quyền và sở hữu trí tuệ rất quan trọng, đặc biệt là các dữ liệu liên quan đến thiết kế dạng hình ảnh, như các bản vẽ thiết kế thời trang, thiết kế logo, bao bì, bản vẽ xây dụng, bản vẽ kỹ thuật ... Khi một đơn xin đăng ký bản quyền được tiếp nhận tại cơ quan kiểm định và cấp bằng sở hữu trí tuệ, cần có thời gian xác minh, kiểm định và sửa đổi. Các tài liệu này sẽ được gửi đến nhiều nơi khác nhau. Vì vậy có khả năng cao bị rò rỉ, đánh cắp và sửa đổi. Để ngăn chặn các cuộc tấn công như vậy, kỹ thuật AES sử dụng khóa 256 bit được sử dụng để cung cấp bảo mật cho hình ảnh kỹ thuật số

### Scenario
<img  src="https://scontent.fsgn19-1.fna.fbcdn.net/v/t1.15752-9/273052665_4955273054550537_3257602169887012519_n.png?_nc_cat=100&ccb=1-7&_nc_sid=ae9488&_nc_ohc=64eoREtZ-qwAX8b0RHC&_nc_ht=scontent.fsgn19-1.fna&oh=03_AdQXj3FSelVQyppEPhl2QdXwX4zc3JNWR6x8Sa5RzhgpiA&oe=6455FD5E">

<img src= "https://scontent.xx.fbcdn.net/v/t1.15752-9/339253955_702893334966767_6350457726693590808_n.png?stp=dst-png_s417x417&_nc_cat=104&ccb=1-7&_nc_sid=aee45a&_nc_ohc=zhZMnnq67T8AX_tKXUE&_nc_ad=z-m&_nc_cid=0&_nc_ht=scontent.xx&oh=03_AdQZWbK2uCmQFyum2YLiBX5M7lvjH3HRk3oQp23OPgwdLw&oe=64572F8A">

Nguy cơ
- Con người
- Nội gián

|Suject| Description |
|------|-----|
| Tài sản cần bảo vệ | Dữ liệu dạng hình ảnh về các thiết kế |
| Các bên liên quan | Tổ chức tiếp nhận và thẩm định đơn xin đăng ký bản quyền (ví dụ Cục sở hữu trí tuệ Việt Nam)|
||Bên tấn công - đánh cấp dữ liệu
| Security Goals | Bảo đảm tính bí mật, toàn vẹn, sẵn sàng của bản thiết kế |

## 2. Solution
 <img src= "https://scontent.fsgn7-1.fna.fbcdn.net/v/t1.15752-9/338791441_1591396884698819_5028458497922858237_n.png?_nc_cat=100&ccb=1-7&_nc_sid=ae9488&_nc_ohc=pdio1WLqgM0AX_YAudX&_nc_ht=scontent.fsgn7-1.fna&oh=03_AdT_NF_zsVGYN0nkTF26H-Lzr-1pAepOBtZNvICSAVzZ9Q&oe=64570AC9">
 
 
 <img src="https://scontent.fsgn7-1.fna.fbcdn.net/v/t1.15752-9/338527868_909508380382925_4664036545290249084_n.png?_nc_cat=108&ccb=1-7&_nc_sid=ae9488&_nc_ohc=KDhPcrZxTPUAX8dH27r&_nc_oc=AQkxrFu_-mInWsf4GojvWvAyVrykhe6fsJOB89kSzpZMGlQ3k8OIVDMV1NwcNYZ3UvhHRDyE5nRgFMpPy8_EULgu&_nc_ht=scontent.fsgn7-1.fna&oh=03_AdSD-FLk3bUds0lCZJ4uu9zi1w3dYB_55nOFe2g_qQYVkQ&oe=64570E2E">


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
| Viết báo cáo | x | x |
| Làm power point| x | x |
| Demo |  |  |
