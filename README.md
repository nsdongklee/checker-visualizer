# checker_visualizer

> `checker_visualizer` 는  `push_swap` 과제의 실행프로그램 중 `checker` 의 동작 및 사용과 유사하고, 데이터의 시각화를 통해서 최적화에 참고하는 간단한 도구 입니다.

### Dependency

```shell
# 파이썬 패키지가 업그레이드 되어있지 않다면 아래 명령어를 입력
pip3 install --upgrade pip --user

# 필요한 라이브러리 설치
pip3 install matplotlib
pip3 install PyQt5
```

### Usage

```shell
sh checker_visualizer.sh 시작숫자 끝숫자
```

> 예시 : `sh checker_visualizer.sh 0 100` 

- 쉘 스크립트를 실행해도 되고 체커처럼 사용해도 됩니다. 다만, 단독으로 실행하기 위해서는 `$ARG` 를 반드시 `export` 해줘야 합니다.
- `push_swap` 폴더 내에 `git clone ~` 하거나 쉘 스크립트에서 실행파일 경로 변경을 하면 됩니다.
- **프로그램 종료** : 키보드의 `q` 버튼을 누르면 화면이 없어지면서 종료됩니다.
- **프로그램 중지 및 재시작** : 프로그램 화면 위에서 마우스 클릭을 하면 중지 및 재시작 됩니다.

- **주의사항** : 프로그램을 켜놓은 상태에서는 계속 루프가 돌아가는 상태입니다.

### 프로토타입 영상

<img width="80%" src="https://github.com/dannylee93/checker_visualizer/blob/main/prototype_gif/checker_visualizer_prototype.gif"/>

