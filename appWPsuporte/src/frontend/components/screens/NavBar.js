import React from 'react';
import { Image, Text, View } from 'react-native';

import { navStyles } from '../styles/index';

const NavBar = () => {
  return(
  <View style={navStyles.navBar}>
    <Text style={navStyles.textNavBarTitle}>SUPORTE</Text>
    <View style={navStyles.txtNameTec}>
      <Text>Téc.   </Text>
      <Text style={navStyles.txtNameTecText}>CARLOS</Text>
      <Image resizeMode="contain" source={require('../../../frontend/img/profile.png')} style={navStyles.profileImage} />
      </View>
  </View>
  )
}


export default NavBar;