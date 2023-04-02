# Cryptography_Project
A Fast Image Encryption Scheme Based on AES
## 1. Topic overview

### Abstract
Ngày nay thì việc đăng ký bản quyền và sở hữu trí tuệ rất quan trọng. Đặc biệt là việc bảo vệ các dữ liệu liên quan đến thiết kế dạng hình ảnh, như các bản vẽ thiết kế thời trang, thiết kế logo, bản vẽ xây dựng...Bởi vì việc đăng ký bản quyền cần thời gian xác minh và được lưu ở nhiều nơi nên có thể bị rò rỉ, đánh cắp hoặc sửa đổi. Nên mục tiêu của đồ án này hướng đến việc mã hóa các dữ liệu dạng hình ảnh thông qua mã hóa bất đối xứng AES. 
### Scenario

## 2. Solution
Trong quá trình mã hóa hình ảnh AES, hình ảnh được chia thành các khối 128 bit, mỗi khối được mã hóa bằng cách sử dụng một khóa đối xứng. Khóa này được tạo ra bằng cách sử dụng một thuật toán tạo khóa, chẳng hạn như PBKDF2 hoặc scrypt. Khóa đối xứng được sử dụng để thay đổi các bit trong các khối hình ảnh, làm cho chúng trở nên khó đọc được.

Quá trình mã hóa hình ảnh bằng AES được thực hiện qua 10 vòng lặp. Mỗi vòng lặp bao gồm các bước: SubBytes, ShiftRows, MixColumns và AddRoundKey. Các bước này đảm bảo rằng mỗi khối hình ảnh được mã hóa một cách an toàn và khó phá hủy.

Sau khi hoàn thành quá trình mã hóa, hình ảnh đã được mã hóa sẽ trở thành một loạt các khối 128 bit không thể đọc được. Để đọc lại hình ảnh, quá trình giải mã được thực hiện bằng cách sử dụng khóa đối xứng để thực hiện các bước ngược lại, giải mã các khối và khôi phục hình ảnh ban đầu.

### Tools and resources

## 3. Deploy plan

## 4. Implementation Plan
