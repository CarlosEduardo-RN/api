import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

// import { Container } from './styles';

const Atendimentos = () => {
    return (
        <View style={styles.container}>
            <Text>Atendimentos </Text>
        </View>
    );
}
const styles = StyleSheet.create({
    container:{
      height:'100%',
      width:'100%',
      backgroundColor:'#fff',
      padding: 10
    }
  })

export default Atendimentos;