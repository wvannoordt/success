out_dir := bin
target  := ${out_dir}/success

main: setup
	g++ main.cc -o ${target}

setup:
	mkdir -p ${out_dir}

clean:
	rm -rf ${out_dir}
