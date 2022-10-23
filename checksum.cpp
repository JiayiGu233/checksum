#include <iostream>
#include <climits>
unsigned int add_checksum( unsigned int n );
void add_checksum( unsigned int array[], std::size_t capacity );
bool verify_checksum( unsigned int n );
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );
int arr[8]{};
unsigned int add_checksum( unsigned int n ){
if(n>99999999){return UINT_MAX;}
else{int temp=n;
for(int i=0;i<8;i++){
arr[i]=temp%10;
temp=temp/10;}}
int sum{0};
for(int j=0;j<8;j++){
	if(j%2==0){
		if((arr[j]*2)>9){sum+=(1+(arr[j]*2)%10);}else{sum+=(arr[j]*2);};
	}else{sum+=arr[j];}}
int ans{0};
ans=(sum*9)%10+n*10;
return ans;}

void add_checksum( unsigned int array[], std::size_t capacity ){
  for(int i=0;i<capacity;i++){
    array[i]=add_checksum(array[i]);}}
bool verify_checksum( unsigned int n ){
  if(n>999999999||(
  add_checksum(n/10)!=n)){return false;}else{return true;}}

unsigned int remove_checksum( unsigned int n ){if (verify_checksum(n)){return n/10;}else{return UINT_MAX;}}

void remove_checksum( unsigned int array[], std::size_t capacity ){
for(int i=0;i<capacity;i++){
    array[i]=remove_checksum(array[i]); }}

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() {
	
	unsigned int value_to_protect{21352411};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
  
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	
	add_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;
    return 0;
}
#endif