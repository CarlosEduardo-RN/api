import React from 'react';
import { Text, View } from 'react-native';
import { dashStyles } from '../styles';

import Line from '../graficos/Line';
import Pie from '../graficos/Pie';
import Bars from '../graficos/Bar';
import Radars from '../graficos/Radar';


const Dashboard = () => {
  return (
    <View style={dashStyles.window}>
        <View style={dashStyles.card}>
            <Line />
        </View>
        <View style={dashStyles.card}>
            <Text style={dashStyles.atFinalizado}>ATENDIMENTOS FINALIZADOS</Text>
            <Pie />
            <Text style={dashStyles.atNfinalizado}>ATENDIMENTOS NÃO FINALIZADOS</Text>
        </View>
        <View style={dashStyles.card}>
            <Text>TOTAL DE ATENDIMENTOS RELACIONADOS À HARDWARE E SOFTWARE</Text>
            <Bars />
        </View>
        <View style={dashStyles.card}>
            <View style={dashStyles.txtRadar}>
                <Text>LOCAIS COM MAIOR INDICE DE ATENDIMENTOS POR TIPO</Text>
            </View>
            <Radars />
        </View>
    </View>
  )
}

export default Dashboard;