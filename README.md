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
